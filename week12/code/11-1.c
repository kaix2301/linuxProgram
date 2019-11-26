#include "my.h"

int ascii_to_integer(char *);

int main()
{
	int i = 0;
	pid_t pid;
	int r_num;
	int pipefd[2];
	char buf[65538];
	memset(buf, 0, sizeof(buf));
	
	if(pipe(pipefd) < 0)
	{
		perror("pipe failed.\n");
		return -1;
	}

	pid = fork();
	if(pid < 0)
	{
		perror("fork1 failed.\n");
		return -1;
	}
	else if(pid == 0)
	{
		sleep(1);
		close(pipefd[1]);

		close(pipefd[0]);
		exit(0);
	}
	else
	{
		close(pipefd[0]);
		i = 0;
		while(i < 65538)
		{
			if(write(pipefd[1], "0", 1) < 0)
				break;
			i++;
			printf("write number %d\n", i);
		}
		close(pipefd[1]);
		exit(0);		
	}
}



