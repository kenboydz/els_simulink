/*thread safe
 * @note not allowed to use in isr that is time-critical or beyond rtos
*/
#ifndef __ELS_BRIDGE_H__
#define __ELS_BRIDGE_H__

#include <stdint.h>
#include <stdbool.h>

#include "CException.h"

#include "els.h"
#include "els_queue.h"
#include "els_bridge_port.h"


#define ELS_BRIDGE_ON_COMMAND_MAX_ARGS_NUM  4  // the max number of arguments in els_bridge_on_command()


typedef enum {
    ElsBridgeType_Int8,
    ElsBridgeType_Uint8,
    ElsBridgeType_Int16,
    ElsBridgeType_Uint16,
    ElsBridgeType_Int32,
    ElsBridgeType_Uint32,
    ElsBridgeType_Float,
    ElsBridgeType_Str,
    ElsBridgeType_Obj,
    ElsBridgeType_Fun
} ElsBridgeType;


typedef enum{
    ElsBridgeError_RecvChecksumError,
    ElsBridgeError_RecvSeqNoMissingError,
    ElsBridgeError_RecvRecIdMissingError,
    ElsBridgeError_RecvDataByteMissingError
} ElsBridgeError;


typedef struct _ElsBridge {
	/** public */
    // input
    // output

	/** private */
	// parameter
    uint32_t _send_filter_mask;
	// variable
    uint_least8_t _send_seq_no;
    uint_least8_t _send_checksum;
    ElsQueue _send_queue;
    uint_least8_t _recv_seq_no;
    uint_least8_t _recv_checksum;
    ElsQueue _recv_queue;
    bool _recv_is_last_byte_esc;
    bool _recv_is_on_receive;  // false if some error happens
} ElsBridge;

ElsBridge bridge;


//---------------------------------------------------------------------------------------------------//


typedef struct {
    const uint_least8_t * const send_buf;
    const int16_t send_buf_size;
    const uint_least8_t * const recv_buf;
    const int16_t recv_buf_size;
} ElsBridgeInitParam;


void els_bridge_init(const ElsBridgeInitParam * const param);
void els_bridge_update();  // called at idle function or low level task
                           // for send and receive

// user defined received callback function
extern void els_bridge_on_receive(
    int_least8_t rec_id,
    uint32_t data[ELS_BRIDGE_ON_COMMAND_MAX_ARGS_NUM],
    int16_t num
);


// enable rec id transfer
static inline void
els_bridge_enable_send_filter(const uint_least8_t rec_id) {
    bridge._send_filter_mask |= (1 << rec_id);
}

// disable rec id transfer
static inline void
els_bridge_disable_send_filter(const uint_least8_t rec_id) {
    bridge._send_filter_mask &= ~(1 << rec_id);
}

// turn on/off filter
static inline void
els_bridge_turn_filter(const bool turn_on) {
    if (turn_on) {
        bridge._send_filter_mask = UINT32_MAX;
    } else {
        bridge._send_filter_mask = 0U;
    }
}


//---------------------------------------------------------------------------------------------------//


// for internal usage only
void _els_bridge_begin_rec(const uint_least8_t rec_id);
void _els_bridge_end_rec();


// bridge with masked interrupt disabled
// not allowed to use in isr that is time-critical or beyond rtos
// used like:
// ELS_BRIDGE_BEGIN(10);
// ELS_BRIDGE_UINT8(10U);
// ELS_BRIDGE_FLOAT(3.5F);
// ELS_BRIDGE_STR("hello");
// ELS_BRIDGE_END();
#define ELS_BRIDGE_BEGIN(rec) \
    if ((bridge._send_filter_mask & (1U << rec)) != 0U) \
    { \
        els_int_mask_disable(); \
        _els_bridge_begin_rec((uint_least8_t)(rec)); \
        {
#define ELS_BRIDGE_END() \
        } \
        _els_bridge_end_rec(); \
        els_int_mask_restore(); \
    }


#define ELS_BRIDGE_INT8(data)       _els_bridge_uint8(ElsBridgeType_Int8, data)
#define ELS_BRIDGE_UINT8(data)      _els_bridge_uint8(ElsBridgeType_Uint8, data)
#define ELS_BRIDGE_INT16(data)      _els_bridge_uint16(ElsBridgeType_Int16, data)
#define ELS_BRIDGE_UINT16(data)     _els_bridge_uint16(ElsBridgeType_Uint16, data)
#define ELS_BRIDGE_INT32(data)      _els_bridge_uint32(ElsBridgeType_Int32, data)
#define ELS_BRIDGE_UINT32(data)     _els_bridge_uint32(ElsBridgeType_Uint32, data)
#define ELS_BRIDGE_FLOAT(data)      _els_bridge_float(ElsBridgeType_Float, data)
#define ELS_BRIDGE_STR(data)        _els_bridge_str(data)

void _els_bridge_uint8(ElsBridgeType fmt, const uint_least8_t data);
void _els_bridge_uint16(ElsBridgeType fmt, const uint16_t data);
void _els_bridge_uint32(ElsBridgeType fmt, const uint32_t data);
void _els_bridge_float(ElsBridgeType fmt, const float data);
void _els_bridge_str(const char * const data);


//---------------------------------------------------------------------------------------------------//


#endif  // __ELS_BRIDGE_H__
