#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char *args[] = {"./test", NULL};
	printf("call: pid=%d,ppid=%d\n", getpid(), getppid());
	if(execve("./test", args, NULL) < 0)
	{
		perror("execve wrong\n");
	}
	printf("after call\n");
	return 0;
}
