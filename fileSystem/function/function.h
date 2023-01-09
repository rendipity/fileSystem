#ifndef _FUNCTION_H
#define _FUNCTION_H
//根据文件初始化磁盘，若文件不存在则创建文件并格式化
void initSys();
//文件格式化
void my_format();
//进入指定目录
void my_cd(char *dirname);
//1.在当前目录下创建目录 2.在指定目录下创建目录
void my_mkdir(char *dirname);
//删除目录，该目录不一定是当前目录下
void my_rmdir(char *dirname);
//列出指定目录的子目录
void my_ls(char *dirname);
//创建文件 1.在当前目录下创建 2.在指定目录下创建
int my_create(char* filename);
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
int my_read(int fd);
//读文件(物理层):读出指定文件从读写指针开始长度为指定长度的内容到text数组中
int do_read();
//退出文件系统:将虚拟磁盘内容写入文件，释放用户文件打开表和虚拟磁盘空间的内存
int my_exit();
#include <time.h>
#include <stdio.h>
#endif