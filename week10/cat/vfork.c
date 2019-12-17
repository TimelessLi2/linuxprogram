#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <string.h>

int main()
{
   int fd;
   pid_t pid;
   //int status;
   char *ch1 = "hello";
   char *ch2 = "world";
   fd=open("test1.txt",O_RDWR|O_CREAT,0644);
   pid=vfork();
    if(pid <0)
     {
        perror("failed to fork!\n");
        return -1;
     }
   else if(pid==0)
     {
        printf("in child \n");
        write(fd,ch1,strlen(ch1));
        exit(0);
     }
   else
     { 
         sleep(1);// wait child program run
         printf("in parent\n");
         write(fd,ch2,strlen(ch2));
         //wait(&status);// wait chlid program over
         return 0;   
      }
}
