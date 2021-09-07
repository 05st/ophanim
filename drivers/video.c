#include "ports.h"
#include "video.h"

int outchar(char c, int offset, char attr);
void set_cursor(int offset);
int get_cursor();

void kprint_at(char* msg, int col, int row) {
    int offset = 2 * (row * MAX_COLS + col);
    while (*msg != '\0') {
        offset = outchar(*msg++, offset, WHITE_ON_BLACK);
    }
}

void kprint(char* msg) {
    int offset = get_cursor();
    int row = offset / (2 * MAX_COLS);
    int col = (offset - (row * 2 * MAX_COLS)) / 2;
    kprint_at(msg, col, row);
}

int outchar(char c, int offset, char attr) {
    char* vmem = (char*)VIDEO_ADDR;

    if (c == '\n') {
        offset += MAX_COLS * 2;
        offset -= offset % MAX_COLS;
    } else {
        vmem[offset] = c;
        vmem[offset + 1] = attr;
        offset += 2;
    }

    if (offset >= MAX_COLS * MAX_ROWS * 2) {
        // scroll
    }

    set_cursor(offset);
    return offset;
}

void set_cursor(int offset) {
    offset /= 2;
    outb(REG_SCR_CTRL, 14);
    outb(REG_SCR_DATA, (unsigned char)(offset >> 8));
    outb(REG_SCR_CTRL, 15);
    outb(REG_SCR_DATA, (unsigned char)(offset & 0xff));
}

int get_cursor() {
    outb(REG_SCR_CTRL, 14);
    int offset = inb(REG_SCR_DATA) << 8;
    outb(REG_SCR_CTRL, 15);
    offset += inb(REG_SCR_DATA);
    return offset * 2;
}

void clrscr() {
    int size = MAX_COLS * MAX_ROWS;
    char* vmem = (char*)VIDEO_ADDR;
    for (int i = 0; i < size; i++) {
        vmem[i * 2] = ' ';
        vmem[i * 2 + 1] = WHITE_ON_BLACK;
    }
    set_cursor(0);
}

