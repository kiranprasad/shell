#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

void ulink(char* arg)
{
	if (unlink(arg)==-1)
	{
		perror("unlink");
		return;
	}
}

int main(int argc, char** argv)
{
	if (argc!=2)
	{
		cout <<"Syntax error"<<endl<<"Usage: krm filename"<<endl;
		return 0;
	}
	ulink(argv[1]);
	return 0;
}
