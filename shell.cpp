#include<iostream>
#include <unistd.h>
#include <stdlib.h>
 using namespace std;

int main(){
pid_t pid;
if((pid==fork())<0)
{
cout<<"Child process failure";
return -1;
}
if (pid==0){
cout<<"Child process\nHold-a";
}

else if(pid>0){
cout<<"Parent ded";
//exit(0);
}

return 0;
}
