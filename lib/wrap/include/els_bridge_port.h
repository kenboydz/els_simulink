#ifndef __ELS_BRIDGE_PORT_H__
#define __ELS_BRIDGE_PORT_H__

#include <stdbool.h>
#include <stdint.h>

#include "els.h"


void els_bridge_port_init();
bool els_bridge_port_send_avaliable();
void els_bridge_port_send(const uint_least8_t byte);
bool els_bridge_port_recv_avaliable();
uint_least8_t els_bridge_port_recv();

void els_bridge_port_terminate();


#endif  // __ELS_BRIDGE_PORT_H__
