#include "../drivers/video.h"

int main() {
    isr_install();

    asm volatile("sti");
    //init_timer(1);
    init_keyboard();

    return 0;
}

