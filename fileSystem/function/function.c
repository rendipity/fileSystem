#include "function.h"
#include "../global/global.h"
#include "../DISK/disk.h"
#include "../util/util.h"
//根据文件初始化磁盘，若文件不存在则创建文件并格式化
void initSys(){
    printf("initSys 执行了\n");
    //磁盘文件不存在
    if((DISK=fopen(sysName,"a+",))==NULL){
        DISK=fopen(sysName,"r+");
        my_format(DISK)
    }
    //取出引导块判断是否格式化
    if(fread(&block0,sizeof (BLOCK0),1,DISK)==1){
        if(strcmp(block0.diskName,sysName)!=0){
            printf("磁盘未初始化!正在初始化...\n");
            my_format(DISK);
        }
    }
    //进行其他初始化操作
    strcpy(pwd,"/");//设置当前目录
    getFCB(&presentFCB,5,0);//将根目录设置成当前内存中的FCB
    getFAT(FAT1,FAT1_LOCATON);//加载FAT1
    getFAT(FAT2,FAT2_LOCATON);//加载FAT2
    //初始化文件打开表
    for(int i=0;i<MAX_FD_NUM;i++)
        uopenlist[i].topenfile=FREE;//全部设置成0
    return;

}
//启动文件系统执行shell
void sysStart(){
    printf("sysStart 执行了\n");
}
//文件格式化
void my_format(File* disk){
// 引导块 BLOCK0
    strcpy(block0.diskName,sysName);
    strcpy(block0.info,"BlockSize:1024B\nBlockNum:1000 DiskSize:1024000B");
    block0.root = ROOTSTART;
    block0.startblock = DATASTART;
    fseek(DISK,0,SEEK_SET);
    fwrite(&block0,sizeof(BLOCK0),1,DISK);
//FAT
    unsigned short fat[BLOCKNUM*2]
    for (int i = 0; i < BLOCKNUM*2; ++i) {
        if(i<5)
            fat[i]=USED;
        else
            fat[i]=FREE;
    }
    fseek(DISK,1*BLOCKSIZE,SEEK_SET);
    fwrite(fat,sizeof(unsigned short),BLOCK_NUMS*2,DISK);
//根数据区
    FCB rootFCB;
    strcpy(rootFCB.filename,"/");
    rootFCB.attribute = DIRECTORY;       //类型-目录
    rootFCB.free = FREE;        //已使用
    NowTime(&rootFCB.time);
    rootFCB.baseBlockNum = 5;       //起始盘块号
    rootFCB.length = sizeof(FCB);     //长度
    FATchange(5,END);
    addFCB(rootFCB,5);
    initDirectoryBlock(5);
}

//进入指定目录
void my_cd(char *dirname);
//1.在当前目录下创建目录 2.在指定目录下创建目录
void my_mkdir(char *dirname);
//删除目录，该目录不一定是当前目录下
void my_rmdir(char *dirname);
//列出指定目录的子目录
void my_ls(char *dirname);
//创建文件 1.在当前目录下创建 2.在指定目录下创建
int my_create(char filename);
//删除文件
void my_rm(char *filename);
//打开文件 返回文件描述符
int my_open(int fd);
//关闭文件
void my_close(int fd);
//写文件(用户层):获取用户输入，以及输入位置
int my_write(int fd);
//写文件(物理层)
int do_write(int fd,char* text,int len,int position);
//读文件(用户层):检查合法性（fd,len）
int my_read(int fd,int len);
//读文件(物理层):读出指定文件从读写指针开始长度为指定长度的内容到text数组中
int do_read();
//退出文件系统:将虚拟磁盘内容写入文件，释放用户文件打开表和虚拟磁盘空间的内存
int my_exit();
