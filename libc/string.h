#ifndef STRING_H
#define STRING_H

int strlen(char* str);
char* reverse(char* str);

char* itoa(int value, char* str, int base);

int oct_to_bin(char* oct_str, int size);

void backspace(char* str);
void append(char* str, char c);
int strcmp(char* s1, char* s2);

#endif
