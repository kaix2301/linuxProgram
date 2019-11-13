#include "my.h"

int g = 10;
int main()
{
	pid_t pid;
	pid = vfork();

	if(pid < 0)
	{
		perror("vfork failed!\n");
	}
	else if(pid == 0)
	{
		printf("child: pid=%d, g=%d \n",getpid(), g);
		while(g != 0){
			printf("wait for g=0\n");
		}
		_exit(0);
		//return 0;
	}
	else
	{
		printf("parent: pid=%d, g=%d \n",getpid(), g);
		g = g-10;
		printf("parent after: pid=%d, g=%d \n",getpid(), g);
	}
}
