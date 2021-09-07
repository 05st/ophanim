#ifndef PORTS_H
#define PORTS_H

#include "../cpu/types.h"

void outb(uint16_t port, uint8_t data);
unsigned char inb(uint16_t port);

void outw(uint16_t port, uint16_t data);
unsigned short inw(uint16_t port);

#endif
