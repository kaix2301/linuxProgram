#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int global1 = 0;
int global2 = 0;

int main()
{
	int i = 0;
	static int k = 20;
	pid_t pid;

	pid = fork();
	if(pid < 0)
	{
		perror("fork wrong\n");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("child:pid=%d,ppid=%d\n", getpid(), getppid());
		global1 = 999;
		global2 = 1000;
		i = 12;
		k = 19;
		printf("child:global1=%d,global2=%d,i=%d,k=%d\n", global1, global2, i, k);
	}
	else
	{
		printf("parents:pid=%d,ppid=%d\n", getpid(), getppid());
		sleep(5);
		printf("parents:global1=%d,global2=%d,i=%d,k=%d\n", global1, global2, i, k);
	}
	return 0;
}
