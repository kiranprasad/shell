#include <iostream>
#include <cstdio>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

char *buf;

struct stat statf;

void rd(int f1, int f2)
{
	while (read(f1,buf,sizeof(buf))>0)
	{
		//cout << buf;
		write(f2,buf,sizeof(buf));
		//sleep(5);
	}
}

int main(int argc, char** argv)
{
	if (!argc){
		cout << "Usage error."<<endl<<"Syntax kcp srcfile destfile"<<endl;
		return 0;
	}
	int f1 = open(argv[1],O_RDONLY);
	int f2 = open(argv[2],O_WRONLY|O_CREAT|O_EXCL|O_TRUNC,0664);
	if (!f1)
	{
		cout << "Source file does not exist. Try again"<<endl;
		return 0;
	}
	buf = new char [sizeof(statf.st_size)];
	rd(f1, f2);
	close(f1);
	close(f2);
	return 0;
}
