#include "disk.h"
#include "../global/global.h"
#include "../util/util.h"
void addFCB(FCB fcb,int blockNum){
    int offset=blockNum*BLOCKSIZE;
    fseek(DISK,offset,SEEK_SET);
    fwrite(fcb,sizeof(FCB),1,DISK);
}
void FATchange(int loc,int sign){
    FAT1[loc]=sign;
    FAT2[loc]=sign;
    writeToDisk(getBlockOffset(1),sizeof (unsigned short)*BLOCKNUM,FAT1);
    writeToDisk(getBlockOffset(2),sizeof (unsigned short)*BLOCKNUM,FAT2);
}
void writeToDisk(int loc,int size,void* data){
    fseek(DISK,loc,SEEK_SET);
    fwrite(data,size,1,DISK);
}
void readFromDisk(int loc,int size,void *buffer){

}
void initDirectoryBlock(int blockNum,int parentBlockNum){
//加入.和..目录
//.目录
    FCB fcb;
    strcpy(fcb.filename,".");
    fcb.attribute=DIRECTORY;
    NowTime(fcb.time);
    fcb.firstBlock=blocknum;//指向当前目录
    fcb.length=sizeof(FCB);
    addChildFCB(fcb,blocknum);
//..目录
    strcpy(fcb.name,"..");
    fcb.attribute=DIRECTORY;
    NowTime(fcb.time);
    fcb.firstBlock=parentBlockNum;//指向父目录
    fcb.length=sizeof(FCB);
    addChildFCB(fcb,blocknum);
}
void addChildFCB(FCB fcb,int blockNum){
    fseek(DISK,blockNum*BLOCKSIZE+presentFCB.length,SEEK_SET);
    fwrite(fcb,sizeof(FCB),1,DISK);
    presentFCB.length+=sizeof(FCB);
    FCBReload();
}
void FCBReload(){
    addFCB(presentFCB,presentFCB.firstBlock);
}
void getFCB(FCB* fcb,int blockNum){
    fseek(DISK,blockNum*BLOCKSIZE,SEEK_SET);
    fread(fcb,sizeof (FCB),1,DISK);
}
void getFAT(unsigned short* fat,int blockNum){
    fseek(DISK,blockNum*BLOCKSIZE,SEEK_SET);
    fread(fat,sizeof (unsigned short),BLOCKNUM,DISK);
}