#include "../drivers/video.h"
#include "../cpu/isr.h"

int kmain() {
    isr_install();
    irq_install();

    return 0;
}
