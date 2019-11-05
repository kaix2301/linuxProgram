#include "my.h"

int main()
{
	int ret;
	char *arg[] = {"./test1","123", "abc", "hello", "ncu", "edu", NULL};
	printf("call2:pid=%d,ppid=%d\n",getpid(), getppid());
	//PATH=$PATH:/home/linuxProgram/week9/code/classtest2
	ret = execvp("test1", arg);
	printf("after calling! ret=%d\n", ret);
	return 0;
}
