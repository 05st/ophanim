#ifndef PORTS_H
#define PORTS_H

void outb(unsigned short port, unsigned char data);
unsigned char inb(unsigned short port);

void outw(unsigned short port, unsigned short data);
unsigned short inw(unsigned short port);

#endif
