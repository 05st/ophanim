void memcpy(char* dest, char* src, int bytes) {
    for (int i = 0; i < bytes; i++) {
        *(dest + i) = *(src + i);
    }
}

char* itoa(int value, char* str, int base) {
    int i = 0;
    bool neg = false;

    if (value == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    
    if (num < 0 && base == 10) {
        neg = true;
        num = -num;
    }

    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num /= base;
    }

    if (neg) str[i++] = '-';
    str[i] = '\0';

    return str;
}
