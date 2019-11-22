#include "my.h"

int main()
{
	int pid1,pid2,s1,s2,p1,p2,s,p,i,j;
	FILE *fp = fopen("test.txt", "a");

	if(((pid1=fork()) && (pid2=fork())) < 0)
	{
		perror("fail to fork!\n");
		return -1;
	}
	else if(pid1 == 0)
	{
		printf("%d:child1 is running.\n", getpid());

		for(i=0; i<10; i++)
		{
			fprintf(fp,"%d-%d\n", getpid(),i);
		}
		printf("%d:child1 exit now.\n", getpid());
		exit(0);
	}
	else if(pid2 == 0)
	{
		printf("%d:child2 is running.\n", getpid());

		for(j=0; j<10; j++)
		{
			fprintf(fp,"%d-%d\n", getpid(),j);
		}
		printf("%d:child2 exit now.\n", getpid());
		exit(0);
	}
	else
	{
		printf("%d:parent is waiting now.\n", getpid());
		p1 = wait(&s1);
		p2 = wait(&s2);
		fclose(fp);
		printf("%d:parent exit now.\n", getpid());
	}
	exit(0);
}
