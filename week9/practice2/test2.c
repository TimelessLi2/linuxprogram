#include "my.h"
static void_attribute_((constructor)) before_main()
{
 printf("-----before  main !-------\n");
}
static void_attribute_((constructor)) after_main()
{
 printf("-----after  main !-------\n");
}
static void callback1(void)
{
 printf("-------callback1-------!\n");
}
int main(void)
{
printf("main!\n");
return 0;
}
