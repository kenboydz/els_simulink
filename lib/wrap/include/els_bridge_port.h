#ifndef __ELS_BRIDGE_PORT_H__
#define __ELS_BRIDGE_PORT_H__

#include <stdbool.h>
#include <stdint.h>

#include "els.h"


void els_bridge_port_init();
bool els_bridge_port_send_available();
void els_bridge_port_send(int_least8_t byte);
bool els_bridge_port_recv_available();
uint_least8_t els_bridge_port_recv();

void els_bridge_port_terminate();


#endif  // __ELS_BRIDGE_PORT_H__
