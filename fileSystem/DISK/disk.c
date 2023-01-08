#include "disk.h"
#include "../global/global.h"
#include "../util/util.h"
void addFCB(FCB fcb,int blockNum){
    int offset=getBlockOffset(blockNum);
    fseek(DISK,offset,SEEK_SET);
    fwrite(fcb,sizeof(FCB),1,DISK);
}
int getBlockOffset(int blockNum){
    return blockNum*BLOCKSIZE;
}
void FATchange(int loc,int sign){
    FAT1[loc]=USED;
    FAT2[loc]=USED;
    writeToDisk(getBlockOffset(1),sizeof (unsigned short)*BLOCKNUM,FAT1);
    writeToDisk(getBlockOffset(2),sizeof (unsigned short)*BLOCKNUM,FAT2);
}
void writeToDisk(int loc,int size,void* data){
    fseek(DISK,loc,SEEK_SET);
    fwrite(data,size,1,DISK);
}
void initDirectoryBlock(int blockNum,int parentBlockNum){
//加入.和..目录
//.目录
    FCB fcb;
    strcpy(fcb.filename,".");
    fcb.attribute=DIRECTORY;
    NowTime(fcb.time);
    fcb.baseBlockNum=blocknum;//指向当前目录
    fcb.length=1;
    addFCB(fcb,blocknum);
//..目录
    strcpy(fcb.name,"..");
    fcb.type=1;
    fcb.use=USED;
    fcb.time=getTime(t);
    fcb.date=getDate(t);
    fcb.base=parentBlockNum;//指向父目录
    fcb.length=1;
    addFCB(fcb,blocknum);
}