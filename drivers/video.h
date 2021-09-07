#ifndef VIDEO_H
#define VIDEO_H

#define WHITE_ON_BLACK 0x0f
#define RED_ON_BLACK 0x04

#define VIDEO_ADDR 0xb8000

#define MAX_COLS 80
#define MAX_ROWS 25

#define REG_SCR_CTRL 0x3d4
#define REG_SCR_DATA 0x3d5

void kprint_at(char* msg, int col, int row);
void kprint(char* msg);
void clrscr();

#endif
