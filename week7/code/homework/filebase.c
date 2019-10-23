#include <stdio.h>
#include <stdlib.h>

void creatFile_1()
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

void writeFile_1()
{
	char fileName[20];
	char content[100];
	int i = 0;
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
		//use getchar(), it can get '\n'
        printf("Open successfully\ninput something to file,input '$' to over:\n");
		while((content[i]=getchar())!='$')
    		i++;
		content[i+1]='\0';
		fputs(content, fileP);
		printf("write successfully\n");
    }
    fclose(fileP);
}

void readFile_1()
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
		return;
    }
	
    printf("read successfully:");
	rewind(fileP);
    while(fgets(s, sizeof(s), fileP) != NULL)
	{
		printf("%s",s);
	}

    fclose(fileP);
}
