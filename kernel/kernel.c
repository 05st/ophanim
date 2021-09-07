#include "../drivers/video.h"

int main() {
    kprint("test");
    kprint_at("hello", 10, 10);
    clrscr();
    kprint("after clearing\nda screen");

    return 0;
}

