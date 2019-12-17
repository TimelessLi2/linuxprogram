#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int main()
{
  pid_t pid;
  int fd[2],rn,wn;
  char rbuf[30],wbuf[30];
  memset(rbuf,0,sizeof(rbuf));
  memset(wbuf,0,sizeof(wbuf));
  pipe(fd);
  pid=fork()
  if(pid<0)
  {
    perror("fork faild\n");
    return -1;
  }
 else if(pid==0)
  {
   close(fd[0]);
   sprintf(wbuf,"child %d is running.\n",getpid());
   while(1)
   {
      wn=write(fd[1],wbuf,sizeof(wbuf));
      printf("child write to pipe %d byte.\n",wn);





    }
}
}
