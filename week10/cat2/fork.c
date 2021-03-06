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
   int status;
   char ch1[] = {"hello"};
   char ch2[] = {"world"};
   if((fd=open("test1.txt",O_RDWR|O_CREAT,0644))<0)
   {
     perror("open file failed!\n");
     return -1;
    }

   pid=fork();

    if(pid <0)
     {
        perror("failed to fork!\n");
        return -1;
     }
   else if(pid==0)
     {
        write(fd,ch1,strlen(ch1));
        printf("child have done!\n");
        return 0;
     }
   else
     { 
         sleep(1);// wait child program run
         write(fd,ch2,strlen(ch2));
         printf("parent have done!\n");
         wait(&status);// wait chlid program over
         return 0;   
      }
}
