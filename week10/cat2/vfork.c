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
   char ch1[] = {"hellohello"};
   char ch2[] = {"world"};
   if((fd=open("test2.txt",O_RDWR|O_CREAT,0644))<0)
   {
     perror("open file failed!\n");
     return -1;
    }

   pid=vfork();

    if(pid <0)
     {
        perror("failed to fork!\n");
        return -1;
     }
   else if(pid==0)
     {
       if(write(fd,ch1,strlen(ch1)) != (sizeof(ch1)-1))
        {
          perror("faild to child\n");
          return -1;
        }
        printf("child have write done\n");
        exit(0);
     }
   else
     { 
        sleep(2);
        wait(&status);
        if(write(fd,ch2,strlen(ch2)) != (sizeof(ch2)-1))
        {
          perror("faild to parent\n");
          return -1;
        }
        printf("parent have write done\n");  
        
        return 0;
      }
}
