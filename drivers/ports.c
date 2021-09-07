#include "ports.h"

void outb(u16 port, u8 data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

u8 inb(u16 port) {
    u8 res;
    __asm__("in %%dx, %%al" : "=a" (res) : "d" (port));
    return res;
}

void outw(u16 port, u16 data) {
    __asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}

u16 inw(u16 port) {
    u16 res;
    __asm__("in %%dx, %%ax" : "=a" (res) : "d" (port));
    return res;
}
