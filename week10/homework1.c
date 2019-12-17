#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int g=10;

int main()
{
   int l=20;
   int status;
   static int s=30;
   FILE *fp;
   pid_t pid;
   pid=vfork();
   if(pid <0)
     {
        perror("failed to fork!\n");
        return -1;
     }
   else if(pid==0)
     {
        //int p=99;
        char buf[]={"hello"};
        printf("-----address of var-----\n");
        printf("child pid= %d\n&g=%16p\n&l=%16p\n&s=%16p\n\n",getpid(),&g,&l,&s);
        g=100;
        l=200;
        s=300;
       // p=99999;
        execl("./test","test",NULL);
        printf("value in child\n");
        printf("g=%d\nl=%d\ns=%d\n",g,l,s);
         if((fp=fopen("homework1.dat","w+"))==NULL)
{
 perror("failed to create file!\n");
 return -1;
}
 if(fputs(buf,fp)==EOF)
{
 perror("failed to fputs file!\n");
 return -1;
}



        return 0;
        //exit(119);
        //_exit(0);
      }
   else
      {
        //wait(&status);
        //printf("parent:\nexit code from child is %d\n",WEXITSTATUS(status));
        char buf[]={"world"};
        printf("-----address of var in parent-----\n");
        printf("parent :\n&g=%16p\n&l=%16p\n&s=%16p\n",&g,&l,&s);
        printf("value in parent\n");
        printf("parent :\ng=%d\nl=%d\ns=%d\n",g,l,s);
        if((fp=fopen("homework1.dat","w+"))==NULL)
{
 perror("failed to create file!\n");
 return -1;
}
 if(fputs(buf,fp)==EOF)
{
 perror("failed to fputs file!\n");
 return -1;
}

        return 0;
      }

}

