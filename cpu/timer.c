#include "timer.h"
#include "../drivers/video.h"
#include "../libc/string.h"
#include "../drivers/ports.h"
#include "isr.h"

uint32_t tick = 0;

static void timer_callback(registers_t* regs) {
    tick++;
}

void init_timer(uint32_t freq) {
    register_interrupt_handler(IRQ0, timer_callback);
    uint32_t divisor = 1193180 / freq;
    uint8_t low = (uint8_t)(divisor & 0xff);
    uint8_t high = (uint8_t)((divisor >> 8) & 0xff);
    outb(0x43, 0x36);
    outb(0x40, low);
    outb(0x40, high);
}
