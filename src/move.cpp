#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

void move(char* arg1, char* arg2){
if(symlink(arg1,arg2)==-1)
{
perror("symink");
return;
}
unlink(arg1);
}

int main(int argc, char** argv){

if(argc!=3){
cout<<"Syntax error"<<endl<<"Usage: kmv srcfile destfile"<<endl;
return 0;
}
move(argv[1],argv[2]);
return 0;
}
