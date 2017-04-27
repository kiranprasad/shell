#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <cstdio>
using namespace std;

int main(int argc, char** argv){
	chdir("../bin/");
	cout << "The following commands are recognized. Capiche?"<<endl;
	if(execl("../bin/kls","./help",(char*)NULL)==-1)
	perror("exec");

}
