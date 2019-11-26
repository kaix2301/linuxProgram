#include "my.h"

int ascii_to_integer(char *);

int main()
{
	int i = 0, n = 0,s1,s2,s3,sign=1,sum=0;
	char num[4];
	pid_t r1,r2,r3;
	int r_num1, r_num2,r_num;
	int pipefd1[2];
	int pipefd2[2];
	char buf[4096];
	memset(buf, 0, sizeof(buf));
	
	if(pipe(pipefd1) < 0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	if(pipe(pipefd2) < 0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	
	r1 = fork();
	if(r1 < 0)
	{
		perror("fork1 failed.\n");
		return -1;
	}
	else if(r1 == 0)
	{
		close(pipefd1[0]);
		i = 0;
		while(i < 4096)
		{
			sprintf(num, "%04d", i);
			if(write(pipefd1[1], num, 4) == -1)
				break;
			i++;
		}

		if(i == 4096)
			printf("child1 write pipe1 ok\n");
		else
			printf("child1 write pipe1 fail\n");

		close(pipefd1[1]);
		exit(0);
	}
	else
	{
		sleep(1);
		r2 = fork();
		if(r2 < 0)
		{
			perror("fork2 failed.\n");
			return -1;
		}
		else if(r2 == 0)
		{
			close(pipefd1[1]);
			close(pipefd2[0]);
			i = 0;
			r_num1 = 0;
			printf("child2 read from pipe1: \n");
			while(i < 4096)
			{
				if((r_num = read(pipefd1[0], buf,4)) > 0)
				{
					printf("read:%s,", buf);
					//r_num1 += r_num;
					
					if(write(pipefd2[1], buf, 4) == -1)
						sign = 0;
				}
				else
					break;
				i++;
			}
		
			if(i == 4096)
				printf("\nchild2 read pipe1 ok\n");
			else
				printf("\nchild2 read pipe1 fail\n");
			
			if(sign == 1)
				printf("child2 write pipe2 ok\n");
			else
				printf("child2 write pipe2 fail\n");

			close(pipefd1[0]);
			close(pipefd2[1]);
			exit(0);
		}
		else
		{
			sleep(1);
			r3 = fork();
			if(r3 < 0)
			{
				perror("fork3 failed.\n");
				return -1;
			}
			else if(r3 == 0)
			{
				close(pipefd2[1]);
				i = 0;
				r_num2 = 0;
				while(i < 4096)
				{
					if((r_num = read(pipefd2[0], buf, 4)) > 0)
					{
						sum += ascii_to_integer(buf);
						//r_num2 += r_num;
					}
					else
						break;
					i++;
				}
			
				if(i == 4096)
					printf("child3 read pipe2 ok,sum=%d\n",sum);
				else
					printf("child3 read pipe2 fail,sum=%d\n",sum);

				close(pipefd2[0]);
				exit(0);
			}
			else
			{
				wait(&s1);
				wait(&s2);
				wait(&s3);
				exit(0);
			}
		}
	}
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

