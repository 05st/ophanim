#include "../drivers/video.h"

int main() {
    isr_install();

    asm volatile("sti");
    init_timer(1);

    return 0;
}

