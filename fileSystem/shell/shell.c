#include "shell.h"
#include "stdio.h"
#include "../global/global.h"
#include "../function/function.h"
//cd xxx
//mkdir xxx
//rmdir xxx
//ls
//create xxx
//rm xxx
//open xxx
//close xxx
//write 1
//read 1
//exit
//pwd
//help
void help(){
    printf("1-cd xxx\t进入xxx目录\n");
    printf("2-mkdir xxx\t在当前目录下创建xxx子目录\n");
    printf("3-rmdir xxx\t删除当前目录下的xxx子目录\n");
    printf("4-ls\t显示当前目录的文件目录列表\n");
    printf("5-create xxx\t创建xxx文件\n");
    printf("6-rm xxx\t删除xxx文件\n");
    printf("7-open xxx\t打开xxx文件，并返回打开文件的文件描述符，利用文件描述符读写文件\n");
    printf("8-close xxx\t关闭xxx文件\n");
    printf("9-write fd\t向文件描述符为fd的文件写入数据\n");
    printf("10-read fd\t读出文件描述符为fd的文件数据\n");
    printf("11-pwd\t输出当前文件路径\n");
    printf("12-help\t帮助菜单\n");
    printf("13-exit\t退出文件系统\n");
}
void getArguments(char* cmd,char* args){
    char input[100];
    gets(input);
    sscanf(input,"%s %s",cmd,args);
}
void action(char* cmd,char* args){
    if(strcmp(cmd,"help")==0){
        if(strcmp(args,"")!=0){
            printf("%s : too many arguments\n",cmd);
            return -1;
        }
        else{
            help();
            return 0;
        }
    }
    if(strcmp(cmd,"exit")==0){
        if(strcmp(args,"")!=0){
            printf("%s : too many arguments\n",cmd);
            return -1;
        }
        else{
            my_exit();
            return -2;
        }
    }
    if(strcmp(cmd,"pwd")==0){
        if(strcmp(args,"")!=0){
            printf("%s : too many arguments\n",cmd);
            return -1;
        }
        else{
            printf("%s\n",pwd);
            return 0;
        }
    }
    if(strcmp(cmd,"ls")==0){
        if(strcmp(args,"")!=0){
            printf("%s : too many arguments\n",cmd);
            return -1;
        }
        else{
            my_ls();
            return 0;
        }
    }
    if(strcmp(cmd,"mkdir")==0){
        if(strcmp(args,"")==0){
            printf("%s need [directory name]\n",cmd);
            return -1;
        }
        else{
            my_mkdir(args);
            return 0;
        }
    }
    if(strcmp(cmd,"rmdir")==0){
        if(argc!=2){
            printf("%s need [directory name]\n",cmd);
            return -1;
        }
        else{
            my_rmdir(args);
            return 0;
        }
    }
    if(strcmp(cmd,"cd")==0){
        if(strcmp(args,"")==0){
            printf(" %s need [directory name]\n",cmd);
            return -1;
        }
        else{
            my_cd(args);
            return 0;
        }
    }
    if(strcmp(cmd,"create")==0){
        if(strcmp(args,"")==0){
            printf("%s need [file name]\n",cmd);
            return -1;
        }
        else{
            my_create(args);
            return 0;
        }
    }
    if(strcmp(cmd,"rm")==0){
        if(strcmp(args,"")==0){
            printf("%s need [file name]\n",cmd);
            return -1;
        }
        else{
            my_rm(args);
            return 0;
        }
    }

    if(strcmp(cmd,"open")==0){
        if(strcmp(args,"")==0){
            printf("%s need [file name]\n",cmd);
            return -1;
        }
        else{
            my_open(args);
            return 0;
        }
    }
    if(strcmp(cmd,"close")==0){
        if(strcmp(args,"")==0||atoi(args)==0){
            printf("%s need [fd num]\n",cmd);
            return -1;
        }
        else{
            my_close(a);
            return 0;
        }
    }

    if(strcmp(cmd,"write")==0){
        if(strcmp(args,"")==0||atoi(args)==0){
            printf("usage %s [fd] [write method]\n",argv[0]);
            return -1;
        }
        else{
            int fd=atoi(args);
            if(my_write(fd)==0){
                printf("succeed write to fd %d\n",fd);
                return 0;
            }
            return 0;
        }
    }

    if(strcmp(argv[0],"read")==0){
        if(strcmp(args,"")==0||atoi(args)==0){
            printf("%s need [fd num]\n",args);
            return -1;
        }
        else{
            int fd=atoi(args);
            if(my_read(fd)==0)
                printf("read fd %d with %d bytes\n",a,len);
            return 0;
        }
    }

}
//启动文件系统执行shell
void sysStart(){
    printf("sysStart 执行了\n");
    char cmd[10]="";
    char args[30]="";
    while(1){
        printf("[%s %s]# ",sysName,pwd);
        getArguments(cmd,args);
        int result=action(cmd,args);
        if(result==-2)
            break;
    }
    printf("sysStart 结束了\n")
}