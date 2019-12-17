#include "my.h"

void fun(void *arg)
{

printf("work thread is running.pid=%d\n",getpid());
}
int main()
{
  pthread_t pid;
  int ret;
  ret = pthread_create(&tid,NULL,(void *(*)())fun,NULL);
  if(ret !=0)
  {
    perror("create failed!\n");
    return -1;
  }
  pthread_join(tid,NULL);
  printf("MASTER %d : ALL Done!\n",getpid());
  return 0;
}
