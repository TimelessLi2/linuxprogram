#include"my.h"
int main()
{
 int ret;
 printf("caller1:pid = %d,ppid = %d\n",getpid(),getppid());
 ret=system("./test1 123 445 hello world");
 printf("After calling\n");
 sleep(10);
 printf("ret = %d,ret");
 return 0
}
