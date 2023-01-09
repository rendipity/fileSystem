#ifndef _DISK_H
#define _DISK_H
void addFCB(FCB fcb,int blockNum);
int getBlockOffset(int blockNum);
void FATchange(int loc,int sign);
void writeToDisk(int loc,int size,void* data);
void initDirectoryBlock(int blockNum);
void addChildFCB(FCB fcb,int blockNum);
void getFCB(FCB* fcb,int blockNum);
void getFAT(unsigned short* fat,int blockNum);
void readFromDisk(int loc,int size,void *buffer);
void FCBReload();
#include <stdio.h>
#endif