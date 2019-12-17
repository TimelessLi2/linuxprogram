#include "my.h"

int main()
{
	int pid1, pid2, pid3, status, rv;
    //FILE *fp;
    int fp;
    //fp=fopen("out1.dat","w+");
    fp=open("out1.dat",O_RDWR|O_CREAT,0644);
    char ch1[]={"123456789"};
	pid1 = fork();
	if(pid1 < 0 )
	{
		perror("fork1 failed!\n");
		return -1;
    }
	else if(pid1 == 0)
	{
        //fprintf(fp,"pid = %d ",getpid,ch1);
        write(fp,ch1,strlen(ch1));
		printf("child1 pid = %d\n", getpid());
		sleep(3);
		exit(18);
	}
	else 
	{   
        printf("parent fork child2\n");
        pid2= fork();
        if(pid2<0)
        {
		perror("fork2 failed!\n");
		return -1;
         }
         else if(pid2 == 0)
	    {
        //fprintf(fp,"pid = %d ",getpid,ch1);
        write(fp,ch1,strlen(ch1));
		printf("child2 pid = %d\n", getpid());
		sleep(3);
		exit(99);
	    }
        else
        { 
           printf("parent fork child3\n");
           pid3=fork();
           	if(pid3 < 0 )
	       {
		    perror("fork3 failed!\n");
		     return -1;
           }
           	else if(pid3 == 0)
	        {
                 //fprintf(fp,"pid = %d ",getpid,ch1); 
                 write(fp,ch1,strlen(ch1));
		        printf("child3 pid = %d\n", getpid());
		        sleep(3);
		        exit(108);
	         }
	       else
	       {
		     printf("parent waiting child end!\n");
		     rv = wait(&status);
		      printf("1:child %d end.exit code is %d\n", rv,WEXITSTATUS(status));
             rv=0;
             status=0;
		rv = waitpid(pid1, &status, 0);
		printf("2:child %d end.exit code is %d\n", rv, WEXITSTATUS(status));
             rv=0;
             status=0;
		rv = waitpid(pid2, &status, WNOHANG);
		printf("3:child %d end.exit code is %d\n", rv, WEXITSTATUS(status));
            return 0;
	        }
        }
    }
	
}

