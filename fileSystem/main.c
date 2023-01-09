#include "function/function.h"
#include "global/global.h"
#include "./shell/shell.h"
char sysName[20]="virtualDisk";
char pwd[80];
FILE * DISK;
BLOCK0 block0;
unsigned short FAT1[BLOCKNUM];
unsigned short FAT2[BLOCKNUM];
FCB presentFCB;
int main(){
	initSys();
	sysStart();
	return 0;
}
