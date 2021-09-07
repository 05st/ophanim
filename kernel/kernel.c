#include "../drivers/ports.h"

int main() {
    outb(0x3d4, 14);
    int pos = inb(0x3d5);
    outb(0x3d4, 15);
    pos += inb(0x3d5);

    int offset = pos*2;

    char* vmem = 0xb8000;
    vmem[offset] = 'A';
    vmem[offset + 1] = 0x0f;

    return 0;
}

