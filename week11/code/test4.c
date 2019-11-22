#include "my.h"

int main()
{
	int pid1,pid2,s1,s2,p1,p2,s,p;
	if(((pid1=fork()) && (pid2=fork())) < 0)
	{
		perror("fail to fork!\n");
		return -1;
	}
	else if(pid1 == 0)
	{
		printf("%d:child1 is running.\n", getpid());
		printf("%d:child1 exit now.\n", getpid());
		//while(1);
		exit(120);
	}
	else if(pid2 == 0)
	{
		printf("%d:child2 is running.\n", getpid());
		printf("%d:child2 exit now.\n", getpid());
		//while(1);
		exit(130);
	}
	else
	{
		printf("%d:parent is waiting zombie now.\n", getpid());
		p1 = wait(&s1);
		p2 = wait(&s2);
		/*
		p = wait(&s);
		if(WEXITSTATUS(s) == 120)
		{
			printf("%d:parent:first child is child1 %d\n", getpid(), p);
		}
		else if(WEXITSTATUS(s) == 130)
		{
			printf("%d:parent:first child is child2 %d\n", getpid(), p);
		}
		else
		{
			printf("%d:parent:first child is unknowen %d\n", getpid(), p);
		}
		*/
		
		//while((pid =wait(&s)) != -1)
		while((p =waitpid(pid2,&s,WNOHANG)) != -1)
		{
			if(WIFEXITED(s))
				printf("child %d exit normally.exit code=%d\n",p,WEXITSTATUS(s));
			else if(WIFSIGNALED(s))
				printf("child %d exit by signal.signal no=%d\n",p,WTERMSIG(s));
			else
				printf("Not know exit\n");
		}
		
		printf("%d:parent exit now.\n", getpid());
	}
	exit(0);
}

//ps -aux | grep test1
