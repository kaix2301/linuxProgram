#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	FILE *fp;
	char buf[] = "hello word";
	
	if((fp = fopen("test.txt", "w")) == NULL)
	{
		perror("file to fopen");
		return -1;
	}

	if(fputs(buf,fp) == EOF)
	{
		perror("file to puts");
		return -1;
	}
	exit(0);
}
