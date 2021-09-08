#ifndef MEM_H
#define MEM_H

#include <stdint.h>

#define FREE_MEM_ADDR 0x10000

void memcpy(char* dest, char* src, int bytes);

uint32_t kmalloc(uint32_t size, int align, uint32_t* addr);

#endif
