#include "timer.h"
#include "../drivers/video.h"
#include "../kernel/util.h"
#include "../drivers/ports.h"
#include "isr.h"

uint32_t tick = 0;

static void timer_callback(registers_t regs) {
    tick++;
    kprint("Ur Mom Is This Fat: ");
    char tick_ascii[256];
    itoa(tick, tick_ascii, 16);
    kprint(tick_ascii);
    kprint("\n");
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
