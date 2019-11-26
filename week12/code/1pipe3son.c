#include "my.h"

int ascii_to_integer(char *);

int main(void)
{
	int i = 0, r_num,s1,s2,s3,sum;
	char num[4];

	char buf[4096];
	memset(buf, 0, sizeof(buf));

	int pipefd[2];
	int ret = pipe(pipefd);
	if(ret == -1)
	{
		fprintf(stderr, "creat pipe error (%s)\n", strerror(errno));
		exit(-1);
	}

	pid_t pid;
	pid = fork();
	if(pid == -1)
	{
		fprintf(stderr, "fork1 error (%s)\n", strerror(errno));
		exit(-2);
	}
	else if(pid == 0)
	{
		close(pipefd[0]);
		i = 0;
		while(i < 4096)
		{
			sprintf(num, "%04d", i);
			if(write(pipefd[1], num, 4) == -1)
				break;
			i++;
		}

		if(i == 4096)
			printf("child1 write pipe ok\n");
		else
			printf("child1 write pipe fail\n");

		close(pipefd[1]);
		exit(0);
	}

	pid = fork();
	if(pid == -1)
	{
		fprintf(stderr, "fork2 error (%s)\n", strerror(errno));
		exit(-2);
	}
	else if(pid == 0)
	{
		sleep(1);
		i = 0;
		printf("child2 read from pipe1: \n");
		while(i < 4096)
		{
			if((r_num = read(pipefd[0], buf,4)) > 0)
			{
				printf("read:%s,", buf);
				if(write(pipefd[1], buf, 4) == -1)
					break;
			}
			else
				break;
			i++;
		}
		
		if(i == 4096)
			printf("\nchild2 read pipe ok\n");
		else
			printf("\nchild2 read pipe fail\n");

		exit(0);
	}

	pid = fork();
	if(pid == -1)
	{
		fprintf(stderr, "fork3 error (%s)\n", strerror(errno));
		exit(-2);
	}
	else if(pid == 0)
	{
		sleep(2);
		close(pipefd[1]);
		i = 0;

		while(i < 4096)
		{
			if((r_num = read(pipefd[0], buf, 4)) > 0)
			{
				sum += ascii_to_integer(buf);
			}
			else
				break;
			i++;
		}
			
		if(i == 4096)
			printf("child3 read pipe ok,sum=%d\n",sum);
		else
			printf("child3 read pipe fail,sum=%d\n",sum);

		close(pipefd[0]);
		exit(0);
	}
	
	wait(&s1);
	wait(&s2);
	wait(&s3);
	return 0;
}


int ascii_to_integer( char *string )
{
    int value; value = 0;
    // 逐个把字符串的字符转换为数字。
    while( *string >= '0' && *string <= '9' ){
        value *= 10;
        value += *string - '0';
        string++;
    }
    //错误检查：如杲由于遇到一个非数字字符而终止，把结果设置为0
    if( *string != '\0' )
        value = 0;
    return value;
}



