#include "string.h"

int strlen(char* string) {
    int length = 0;

    while(string[length] != '\0') {
        length++;
    }

    return length;
}

char* reverse(char* str) {
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

    return reverse(str);
}

void backspace(char* str) {
    int len = strlen(str);
    str[len - 1] = '\0';
}

void append(char* str, char c) {
    int len = strlen(str);
    str[len] = c;
    str[len + 1] = '\0';
}

int strcmp(char* s1, char* s2) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') return 0;
    }
    return s1[i] - s2[i]; 
}
