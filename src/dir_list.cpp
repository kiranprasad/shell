#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <dirent.h> 
#include <string.h>
#include <errno.h>
#include <unistd.h>
#define SIZE 100

using namespace std;

void curdir(){
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


}

int main(int argc, char** argv) 
{ 
	int i=0; 
	DIR *p = NULL;
	char fileName[255]; 
	struct dirent *dptr = NULL;     
	p = opendir((const char*)"./");
	if(strcmp(argv[0],"kls")==0)
	curdir();  
	for(i = 0;(dptr = readdir(p)) != NULL; i++) 
	{
		strncpy(fileName, dptr->d_name, 254);
		if(strncmp(fileName,".",sizeof(fileName))!= 0 && strncmp(fileName,"..",sizeof(fileName)!=0))
			cout <<" "<<dptr->d_name<<endl; 
	} 
	cout << endl;
	return 0; 
}
