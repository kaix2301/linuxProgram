#include "my.h"

int main()
{
	int pid;
	if((pid=fork()) < 0)
	{
		perror("fail to fork!\n");
		return -1;
	}
	else if(pid == 0)
	{
		printf("%d:child exit now.\n", getpid());
		exit(0);
	}
	else
	{
		printf("%d:parent is running.\n", getpid());
		while(1);
	}
	exit(0);
}

//ps -aux | grep test1
//ps -ef | grep test1

