#include "my.h"

void fun(void *arg)
{
int TID = pthread_self();
//int TID = syscall(SYS-gettid);
printf("work---%d : getpid return %d\n",TID,TID);
printf("work---%d : pthread_self return %p\n",TID,(void*)pthread_self());
printf("work---%d : will exit!\n",TID);
pthread_exit(NULL);
return NULL;
}
int main()
{
  pthread_t tid;
  int ret;
  ret = pthread_create(&tid,NULL,fun,NULL);
  if(ret !=0)
  {
    perror("create failed!\n");
    return -1;
  }
  pthread_join(tid,NULL);
  ret = pthread_create(&tid,NULL,fun,NULL);
  if(ret !=0)
  {
    perror("create failed!\n");
    return -1;
  }
  pthread_join(tid,NULL);
  printf("MASTER %d : ALL Done!\n",getpid());
  return 0;
}
