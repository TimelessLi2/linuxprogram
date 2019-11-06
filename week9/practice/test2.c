#include "my.h"
 static void_attribute_((constructor)) before_main()
{
 printf("Before Test1 main\n");
}
 static void callback1(void)
{
 printf("callback is running\n");
}
static void callback2(void)
{
 printf("callback2 is running\n");
}
static void callback3(void)
{
 printf("callback3 is running\n");
}
int main(int argc,char *argv[])
{
 int i;
 atexit(callback1);
 atexit(callback2);
atexit(callback3);

}
