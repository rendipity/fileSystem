#ifndef _GLOBAL_H
#define _GLOBAL_H
typedef struct BLOCK0{
    char diskName[200];
    char info[200];
    unsigned short root;//根目录块号
    int startBlock;//数据块号
}BLOCK0;
typedef struct Date{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
}Date;
typedef struct FCB{
    char filename[20];
    char exName[6];
    Date time;
    unsigned  char attribute; //0 目录；1文件
    unsigned short firstBlock;
    unsigned long length;
    char free;
}FCB;
    extern char sysName[];
    extern FILE * DISK;
    extern BLOCK0 block0;
    extern char pwd[];
    extern FCB presentFCB;
    extern unsigned short FAT1 [];
    extern unsigned short FAT2 [];

//常量
#define BLOCKSIZE 1024
#define BLOCKNUM 1000
#define END 65535
#define FREE 0
#define USED=-1
#define ROOTBLOCKNUM 2
#define MAXOPENFILE 10
#define FCBSIZE 48
#define ROOTSTART 5
#define DATASTART 7
#define DIRECTORY 1
#define DOCUMENT 0
#endif