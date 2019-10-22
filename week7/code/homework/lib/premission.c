#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void changePermission()
{
	char fileName[20];
	int mod;

	printf("Please input filename:");
	scanf("%s",fileName);
	
	printf("Please input mod:");
	scanf("%o",&mod);
	if(chmod(fileName, mod) == -1)
	{
		printf("Change permission wrong\n");
	}
	else
	{
		printf("Change permission successfully\n");
	}
	
}

void lookChangePermission()
{
	char fileName[20];
	struct stat fileInfo;
	int mod;
	int sign;

	printf("Please input filename:");
	scanf("%s",fileName);
	
	if(stat(fileName, &fileInfo) < 0)
		printf("Look wrong\n");
	else
	{
		unsigned int mask = 0000777;
        unsigned int access = mask & fileInfo.st_mode;
        printf("permission:%o\n", access);
	}

	printf("Do you want to change permission(1/0):");
	scanf("%d",&sign);
	if(sign == 1)
	{
		printf("Please input mod:");
		scanf("%o",&mod);
		if(chmod(fileName, mod) == -1)
		{
			printf("Change permission wrong\n");
		}
		else
		{
			printf("Change permission successfully\n");
		}
	}
}

