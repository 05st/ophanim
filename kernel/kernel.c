#include "../drivers/video.h"
#include "../cpu/isr.h"
#include "../libc/string.h"

int kmain() {
    isr_install();
    irq_install();

    return 0;
}

void handle_input(char* input) {
    if (strcmp(input, "END") == 0) {
        kprint("Halting...\n");
        asm volatile("hlt");
    }
    kprint(input);
    kprint("\n");
}
