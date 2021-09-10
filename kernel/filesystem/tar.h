#ifndef TAR_H
#define TAR_H

typedef struct {
    char name[100];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    char cksum[8];
    char typeflag[1];
    char linkname[100];
    char magic[6];
    char version[3];
    char uname[32];
    char gname[32];
    char devmajor[8];
    char devminor[8];
    char prefix[155];
} tar_t;

void read();
void write();

int lookup(tar_t* archive, char* filename, tar_t* out);

#endif
