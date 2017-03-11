#include <iostream>
#include <fcntl.h>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <utime.h>

using namespace std;

void touch(char* file){
	int filedesc = open(file, O_RDWR);
	//cout <<filedesc;
	if (filedesc==-1)
	{
	//	cout <<"Where are you?";
		open(file,O_RDWR|O_CREAT|O_EXCL,0664);
		//utime(file, 0);
	}
	else
		utime(file,0);
}

int main(int argc , char** argv){

	if (!argc)
	{cout<<"Error"<<endl;
		return -1;}
	touch(argv[1]);
	return 0;
}
