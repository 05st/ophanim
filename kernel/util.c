void memcpy(char* dest, char* src, int bytes) {
    for (int i = 0; i < bytes; i++) {
        *(dest + i) = *(src + i);
    }
}

unsigned long strlen(const char* string) {
    int length = 0;

    while(string[length] != '\0') {
        length++;
    }

    return length;
}

char* strrev(char* str) {
    int index;
    int length = strlen(str);
    int midpoint = length / 2;

    for(index = 0; index < midpoint; index++) {
        char left = str[index];
        char right = str[length - 1 - index];

        str[index] = right;
        str[length - 1 - index] = left;
    }

    return str;
}

char* itoa(int value, char* str, int base) {
    int i = 0;
    char neg = 0;

    if (value == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    
    if (value < 0 && base == 10) {
        value = 1;
        value = -value;
    }

    while (value != 0) {
        int rem = value % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        value /= base;
    }

    if (neg) str[i++] = '-';
    str[i] = '\0';

    return strrev(str);
}
