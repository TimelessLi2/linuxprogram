#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <string.h>

int g=10;
int main()
{

 int t=20;
 static int s=30;
 pid_t pid;
 pid=vfock();
 //pid =fork();
 if(pid<0)
 {
   perror("vfock failed\n");
   return -1;
}
 else if(pid==0)
{
   printf("child pid =%d:&g=%p,&t=%p,&s=%p\n",getpid(),&g,&t,&s);
   g=100;
   t=200;
   s=200;
   printf("after child pid =%d:&g=%p,&t=%p,&s=%p\n",getpid()&g,&t,&s);
   slep(3);
  _exit(0);
  //exit(0);
  //return -1;
}
 else
{
  printf("parent pid = %d:&g=%p,&t=%p,&s=%p\n",getpid(),&g,&t,&s);
  printf("parent pid = %d:&g=%p,&t=%p,&s=%p\n",getpid(),g,t,s);
  return 0;
}
}
