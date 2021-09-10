#include "tar.h"

#include "../libc/string.h"

int lookup(tar_t* archive, char* filename, char** out) {
    tar_t* ptr = archive;
    while (strcmp(ptr->magic, "ustar") == 0) {
        int size = oct_to_bin(ptr->size, 11);
        if (strcmp(ptr->filename, filename) == 0) {
            *out = ptr + 512;
            return size;
        }
        ptr += (((size + 511) / 512) + 1) * 512;
    }
    return 0;
}
