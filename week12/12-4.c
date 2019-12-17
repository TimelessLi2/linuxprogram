#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<erron.h>
#include<wait.h>
#include<time.h>
#include<signal.h>
#include<fcntl.h>
#include<string.h>

int main()
{
  int fd[2];
  pid_t pid;
  if(pipe(fd)==-1)
  {
    fprintf(stderr,"create pipe error.reason:[%s]",strerror(errno));
     return -1;
}
  pid = fork();
  if(pid<0)
  { 
   fprintf(stderr,"create child error.reason:[%s]",strerror(errno));
   }
  else if(pid==0)
   {
     fprintf("[child]:pid = %d,ppid=%d\n",getpid(),getppid());
    close(fd[0]);
    sleep(50);
    exit(0);

    }  
    else
    {
     close(fd[1]);
     wait(NULL);
     return 0;
    }
}
