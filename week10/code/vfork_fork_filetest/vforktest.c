#include "my.h"

int main()
{
	int pid1,p,s,i,j;
	FILE *fp = fopen("vftest.txt", "w");

	if((pid1=vfork()) < 0)
	{
		perror("fail to fork!\n");
		return -1;
	}
	else if(pid1 == 0)
	{
		printf("%d:child is running.\n", getpid());
		for(i=0; i<10; i++)
		{
			printf("child is writing %d\n",i);
			fprintf(fp,"child %d-%d\n", getpid(),i);
		}
		printf("%d:child exit now.\n", getpid());
	}
	else
	{
		printf("%d:parent is running.\n", getpid());
		
		for(j=0; j<10; j++)
		{
			printf("parent is writing %d\n",j);
			fprintf(fp,"parent %d-%d\n", getpid(),j);
		}
		p = wait(&s);
		printf("%d:parent exit now.\n", getpid());
	}
	//fclose(fp);
	exit(0);
}
