#include "my.h"

pthread_rwlock_t rwlock
int g=0;

void *fun(void *praram)
{
 int i;
 pthread_rwlock_rdlock(&rwlock);
 for(i=0;i<loop;i++)
     g++;
 pthread_rwlock_unlock(&rwlock);
 return NULL;
}

int main()
{
   
}
