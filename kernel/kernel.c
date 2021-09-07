#include "../drivers/video.h"

int main() {
    kprint("test");
    kprint_at("hello", 10, 10);
    clrscr();
    kprint("after clearing\nda screen");

    for (int i = 0; i < 24; i++) {
        kprint("test\n");
    }
    kprint("gonna scroll now");

    return 0;
}

