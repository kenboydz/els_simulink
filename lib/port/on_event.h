#ifndef __ON_EVENT_H__
#define __ON_EVENT_H__

#include <stdint.h>

#include "els.h"
#include "els_bridge.h"


void els_on_assert(const char * const name, const uint32_t line);

void els_bridge_on_receive(
    int_least8_t rec_id,
    uint32_t data[ELS_BRIDGE_ON_COMMAND_MAX_ARGS_NUM],
    int16_t num
);


#endif  // __ON_EVENT_H__
