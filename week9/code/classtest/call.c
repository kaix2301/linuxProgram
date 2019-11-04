#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	printf("call: pid=%d,ppid=%d\n", getpid(), getppid());
	system("./test");
	printf("after call\n");
	return 0;
}
