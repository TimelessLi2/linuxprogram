#include "my.h"
//ceshi
void *foo(void * arg)
{
  pruntf("thread is running!\n");
  return (void*)0;
}
int main()
{
  pthread_t tid;
  int red;
  red=pthread_create(&tid,NULL,foo,NULL);
   if(ret)
     {  
        perror("create failed!\n");
       exit -1;	
     }
    //pthread_join(tid,NULL);

   pthread_detach(tid,NULL);
   sleep(5);
  
  return 0;
}
