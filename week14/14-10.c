#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg);
int run_now=1;
void *thread_function(void *arg)
{
  int print_count2=0;
  while(print_count2++<5)
  {
     if(run_now==2)
     {
           printf("function thread is run\n");
           run_now=1;
     }
     else
     {
          printf("function thread is sleep\n");
          sleep(1);
     }
  }
  pthread_exit(NULL);
}
