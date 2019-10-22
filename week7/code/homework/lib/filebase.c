#include <stdio.h>
#include <stdlib.h>

void creatFile()
{
	char fileName[20];
	FILE *fileP;

	printf("Please input filename:");
	scanf("%s",fileName);

    fileP = fopen(fileName, "w");
    if (fileP == NULL)
    {
        printf("creat wrong\n");
    }
	else
    {
        printf("creat successfully\n");
    }
    fclose(fileP);
}

void writeFile()
{
	char fileName[20];
	char content[100];
	FILE *fileP;

	printf("Please input filename:");
	scanf("%s",fileName);

    fileP = fopen(fileName, "w");
    if (fileP == NULL)
    {
        printf("open wrong\n");
    }
	else
    {
        printf("Open successfully, input something to file:\n");
		scanf("%s",content);
		fputs(content, fileP);
		printf("write successfully\n");
    }
    fclose(fileP);
}

void readFile()
{
	char fileName[20];
	char s[1024] = { 0 };
	FILE *fileP;

	printf("Please input filename:");
	scanf("%s",fileName);

    fileP = fopen(fileName, "r");
    if (fileP == NULL)
    {
        printf("read wrong\n");
    }
	else
    {
        printf("read successfully:\n");
        fgets(s, sizeof(s), fileP);
        printf("%s\n",s);
    }
    fclose(fileP);
}
