include "my.h"
static void_attribute_((constructor)) before_main()
{
  printf("before Test1 Main!\n");
}
int main(int arrgc,char *argv[])
{
   int i;
   printf("test1:pid= %d ,ppid=%d\n",getpid(),getppid());
   for(i=0;i<argc;i++)
       printf("test1 : %d : %s \n",i,argv[i]);
   sleep(100);
   return 0;
}
