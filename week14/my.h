#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<limits.h>
#include<string.h>
#include<sys/time.h>
#include<sys/types.h>
struct sendval
{
  int n;
  int s;
};
#define NUM 4

