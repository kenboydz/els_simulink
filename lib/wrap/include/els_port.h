#ifndef __ELS_PORT_H__
#define __ELS_PORT_H__

#include <stdint.h>
#include <sys/time.h>
#include <stdio.h>

#include "els_assert.h"


#define ELS_CPU_FREQ				60000000
#define ELS_INT_MASK				0  // 只屏蔽该优先级以下的中断

// uint_least8_t 的实际保存 byte 值
// 例如， TriCore 每个 uint_least8_t 实际保存为 1byte；
// 例如， C28x 每个 uint_least8_t 实际保存为 2byte；
#define ELS_BYTE_ALIGNMENT				1U

// 有些 MCU 的 FLASH 有最小写入单元限制
// 因此每次写入的地址也必须根据 ELS_FLASH_MIN_UNIT_SIZE 来对齐
// 8 的大小兼容性较强，因此默认为 8
#define ELS_FLASH_MIN_UNIT_SIZE			8U

// #define ELS_PORT_USE_INLINES


volatile int_least8_t _els_int_global_cnt;
volatile int_least8_t _els_int_mask_cnt;


#ifndef TEST_CMOCK


static inline void
els_int_global_disable() {
	if (_els_int_global_cnt++ <= 0) {
		// here: store int state, and disable global int
	}
}


static inline void
els_int_global_enable() {
	if (--_els_int_global_cnt <= 0) {
        _els_int_global_cnt = 0;
		// here: store int state, and enable the global int
	}
}


static inline void
els_int_global_restore() {
	if (--_els_int_global_cnt <= 0) {
        _els_int_global_cnt = 0;
		// here: restore last int state
	}
}


static inline void
els_int_mask_disable() {
	if (_els_int_mask_cnt++ <= 0) {
		els_int_global_disable();
		// here: store mask int, and disable mask int
		els_int_global_restore();
	}
}


static inline void
els_int_mask_restore() {
	if (--_els_int_mask_cnt <= 0) {
		_els_int_mask_cnt = 0;
		els_int_global_disable();
		// here: restore mask int
		els_int_global_restore();
	}
}


static inline void
els_reset_system() {

}


static inline uint32_t
els_get_sys_time() {
    struct timeval tv;    
    gettimeofday(&tv, NULL);
    return (uint32_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}


static inline void
els_delay_us(uint32_t time_us) {
    (void) time_us;
}


#define els_nop()	__asm(" NOP")


#else


void els_int_global_disable();
void els_int_global_enable();
void els_int_global_restore();
void els_int_mask_disable();
void els_int_mask_restore();
void els_reset_system();
uint32_t els_get_sys_time();
void els_delay_us(uint32_t time_us);
void els_nop();


#endif  // ELS_PORT_USE_INLINES


typedef union {
	uint64_t all;
	struct {
		uint_least8_t uint8_0:8;
		uint_least8_t uint8_1:8;
		uint_least8_t uint8_2:8;
		uint_least8_t uint8_3:8;

		uint_least8_t uint8_4:8;
		uint_least8_t uint8_5:8;
		uint_least8_t uint8_6:8;
		uint_least8_t uint8_7:8;
	}bit_8;
	struct {
		uint16_t uint16_0:16;
		uint16_t uint16_1:16;

		uint16_t uint16_2:16;
		uint16_t uint16_3:16;
	}bit_16;
	struct {
		uint32_t uint32_0:32;
		uint32_t uint32_1:32;
	}bit_32;
} ElsFormatBit64;


typedef union {
	uint32_t all;
	struct {
		uint_least8_t uint8_0:8;
		uint_least8_t uint8_1:8;
		uint_least8_t uint8_2:8;
		uint_least8_t uint8_3:8;
	}bit_8;
	struct {
		uint16_t uint16_0:16;
		uint16_t uint16_1:16;
	}bit_16;
} ElsFormatBit32;


typedef union {
	uint16_t all;
	struct {
		uint_least8_t uint8_0:8;
		uint_least8_t uint8_1:8;
	}bit_8;
} ElsFormatBit16;


typedef union {
	float all;
	ElsFormatBit32 bits;
} ElsFormatBitFloat;


typedef union {
	double all;
	ElsFormatBit64 bits;
} ElsFormatBitDouble;


#endif  // __ELS_PORT_H__
