#ifndef _DISK_H
#define _DISK_H
void addFCB(FCB fcb,int blockNum);
int getBlockOffset(int blockNum);
void FATchange(int loc,int sign);
void writeToDisk(int loc,int size,void* data);
void initDirectoryBlock(int blockNum);
#include <stdio.h>
#endif