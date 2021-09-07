#ifndef PORTS_H
#define PORTS_H

#include "../cpu/types.h"

void outb(u16 port, u8 data);
unsigned char inb(u16 port);

void outw(u16 port, u16 data);
unsigned short inw(u16 port);

#endif
