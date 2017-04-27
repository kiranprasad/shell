#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <unistd.h>
#include <errno.h>
#define SIZE 100

using namespace std;

int main(int argc, char **argv){

	char *direct;
	
	int i, sz=SIZE;
	direct = (char*) malloc(SIZE*sizeof(char));
	while (getcwd(direct, sz*sizeof(char))==NULL)
	{
		if (errno == ERANGE)
		{
			sz += 50;
			//allocate more size to buffer
			direct = (char*) realloc(direct, sz * sizeof(char));
		}
	}

	for (i=0;*direct!='\0';i++)
		cout << *direct++;
	cout << endl;
	return 0;
}

