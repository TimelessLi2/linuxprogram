#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int pid1,pid2,pid3;
int fd[2],rn,wn;
char rbuf[1],wbuf[30];
memset(rbuf,0,sizeof(rbuf));
memset(wbuf,0,sizeof(wbuf));
pipe(fd);
pid=fork()
