#include "my.h"

void * fun(void *arg)
{
    struct sendval * k=(struct sendval*)arg;
    int i=0,sum=0;
    for(i-0;i<k->s;i++)
       sum+=i;
//int k=(int)arg;
//printf("worker---%d : pthread_self return %p\n",k,(void*)pthread_self());

printf("worker---%d : pthread_self return %p,sun od %d = %d\n",k->n,(void*)pthread_self().k->s,sum);
pthread_exit(NULL);
return NULL;
}
int main()
{
  pthread_t tid[NUM];
  int ret[NUM],i;
struct sendval d;
  for(i=0;i<NUM;i++){
  d.n=i;
  d.s=100*(i+1);
  ret[i] = pthread_create(&tid[i],NULL,fun,(void*)i);
  if(ret[i]!=0)
  {
    perror("create failed!\n");
    return -1;
  }
  pthread_join(tid,NULL);//rang main() wait child
  }
  printf("MASTER %d : ALL Done!\n",getpid());
  return 0;
}


//create 4 pid
