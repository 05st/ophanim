#include "mem.h"

void memcpy(char* dest, char* src, int bytes) {
    for (int i = 0; i < bytes; i++) {
        *(dest + i) = *(src + i);
    }
}

uint32_t free_mem_addr = 0x10000;

uint32_t kmalloc(uint32_t size, int align, uint32_t* addr) {
    if (align == 1 && (free_mem_addr & 0xFFFFF000)) {
        free_mem_addr &= 0xFFFFF000;
        free_mem_addr += 0x1000;
    }
    if (addr) *addr = free_mem_addr;
    uint32_t ret = free_mem_addr;
    free_mem_addr += size;
    return ret;
}
