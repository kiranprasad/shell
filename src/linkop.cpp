#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define SYM 4
#define HARD 3

using namespace std;

void lnk(char* arg1, char* arg2, int flag)
{
	if (flag==SYM)
		{if(symlink(arg1, arg2)==-1) {perror("symlink"); return;}}
	else if(flag==HARD)
		if(link(arg1, arg2)==-1) {perror("link"); return;}
}

int main(int argc, char** argv)
{
	if (argc<3||argc>4)
		{
		cout<<"Syntax error"<<endl<<"Usage: "<<argv[0]<<"[-s] file1 newlink"<<endl;
		return 0;
		}
	if (argc==4 && strcmp(argv[1]," -s "))
		lnk(argv[2],argv[3],SYM);
//		symlink(argv[2],argv[3]);
	else
		lnk(argv[1],argv[2],HARD);
//		link(argv[1],argv[2]);
	
	return 0;
}
