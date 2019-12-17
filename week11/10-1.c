#include "my.h"
int main()
{
 pid_t pid;
pid = fork();
 if(pid<0)
  {
   perror("faild fork!\n");
}
  else if(pid==0)
{
   printf("child %d is running\n",getpid());
   printf("child will exit!\n");
   exit(120);
}
  else if(pid2==0)
 {
   prntf("parent watting child %d too exit");
}
}
