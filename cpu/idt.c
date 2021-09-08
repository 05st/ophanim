#include "idt.h"
#include "../kernel/util.h"

void set_idt_gate(int n, uint8_t handler) {
    idt[n].low_offset = handler & 0xffff;
    idt[n].sel = KERNEL_CS;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E;
    idt[n].high_offset = (handler >> 16) & 0xffff;
}

void set_idt {
    idt_reg.base = (u32)(&idt);
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
    __asm__ __volatile__("lidt1 (%0)" : : "r" (&idt_reg));
}
