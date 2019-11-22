#include "my.h"
#include <string.h>

int main()
{
	pid_t result;
	int r_num;
	int pipe_fd[2];
	char buf_r[100];
	memset(buf_r, 0, sizeof(buf_r));
	
	if(pipe(pipe_fd) < 0)
	{
		printf("pipe wrong");
		return -1;
	}

	result = fork();
	if(result < 0)
	{
		perror("fork wrong");
		exit;
	}
	else if(result == 0)
	{
		close(pipe_fd[1]);
		if((r_num = read(pipe_fd[0], buf_r, 100)) > 0)
			printf("child read %d char,string is %s\n", r_num, buf_r);
		close(pipe_fd[0]);
		exit(0);
	}
	else
	{
		close(pipe_fd[0]);
		if(write(pipe_fd[1], "first string", 10) != -1)
			printf("parent write 'first string'!\n");
		if(write(pipe_fd[1], "second string", 10) != -1)
			printf("parent write 'second string'!\n");
		close(pipe_fd[1]);
		waitpid(result, NULL, 0);
		exit(0);
	}
}
