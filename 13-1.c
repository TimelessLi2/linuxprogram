#include "my.h"
void sign(int signo)
{
  switch(signo)
  {
     case 1:
        printf("catch SIGHUP\n");
        signal(1,SIG_DFL);
     break;
     case 2:
        printf("catch SIGINT\n");
     break;
     case 3 :
        printf("catch QUIT\n");
     break;
  }
}
int main()
{
   signal(1,sigfun);
   signal(2,sigfun);
   signal(3,sigfun);
   printf("test pid [%d]\n",getpid));
   while(1);                      
   return 0;
}
