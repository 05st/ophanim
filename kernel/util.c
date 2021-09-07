void memcpy(char* dest, char* src, int bytes) {
    for (int i = 0; i < bytes; i++) {
        *(dest + i) = *(src + i);
    }
}

