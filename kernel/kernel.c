#include "../drivers/video.h"
#include "../cpu/isr.h"
#include "../libc/string.h"
#include "../libc/mem.h"

int kmain() {
    isr_install();
    irq_install();

    kprint("Ophanim\n\n");

    return 0;
}

void handle_input(char* input) {
    if (strcmp(input, "END") == 0) {
        kprint("Halting...\n");
        asm volatile("hlt");
    } else if (strcmp(input, "CLR") == 0) {
        clrscr();
    } else {
        char* first_three[3];
        memcpy(first_three, input, 3);
        if (strcmp(first_three, "ADD") == 0) {
            int a = 0;
            int b = 0;
            int index = 4;
            while ((input[index] >= '0') && (input[index] <= '9')) {
                a *= 10;
                a += (int)(input[index] - '0');
                index++;
            }
            index++;
            while ((input[index] >= '0') && (input[index] <= '9')) {
                b *= 10;
                b += (int)(input[index] - '0');
                index++;
            }
            char buffer[256];
            itoa(a+b, buffer, 10);
            kprint(buffer);
            kprint("\n");
        } else {
            kprint("Unrecognized Command: ");
            kprint(input);
            kprint("\n");
        }
    }
}
