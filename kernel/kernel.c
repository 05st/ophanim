#include "../drivers/video.h"

int main() {
    kprint("test");

    kprint_at("hello", 10, 10);

    return 0;
}

