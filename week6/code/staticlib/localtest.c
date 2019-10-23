#include"staticlib.h"
#include<stdio.h>
int main()
{
  
  int a[5]={12,0,-154,7668,334};
  initarray(a,5);
  showarray(a,5);

  printf("max = %4d", max(a,5));
  printf("sum = %4d", sum(a,5));

  return 0;
  
}
