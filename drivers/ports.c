#include "ports.h"

void outb(uint16_t port, uint8_t data) {
    asm volatile("out %%al, %%dx" : : "a" (data), "d" (port));
}

uint8_t inb(uint16_t port) {
    uint8_t res;
    asm("in %%dx, %%al" : "=a" (res) : "d" (port));
    return res;
}

void outw(uint16_t port, uint16_t data) {
    asm volatile("out %%ax, %%dx" : : "a" (data), "d" (port));
}

uint16_t inw(uint16_t port) {
    uint16_t res;
    asm("in %%dx, %%ax" : "=a" (res) : "d" (port));
    return res;
}
