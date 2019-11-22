#include "my.h"

int main()
{
	int pid,s;
	if((pid=fork()) < 0)
	{
		perror("fail to fork!\n");
		return -1;
	}
	else if(pid == 0)
	{
		printf("%d:child is running.\n", getpid());
		printf("%d:child exit now.\n", getpid());
		//while(1);
		exit(120);
	}
	else
	{
		printf("%d:parent is running.\n", getpid());
		while((pid =wait(&s)) != -1)
		{
			if(WIFEXITED(s))
				printf("child %d exit normally.exit code=%d\n",pid,WEXITSTATUS(s));
			else if(WIFSIGNALED(s))
				printf("child %d exit by signal.signal no=%d\n",pid,WTERMSIG(s));
			else
				printf("Not know exit\n");
		}
		printf("%d:parent exit now.\n", getpid());
	}
	exit(0);
}

//ps -aux | grep test1
