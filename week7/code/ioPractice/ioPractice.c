#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void pressKey();
int menu();
void creatFile();
void writeFile();
void readFile();
void changePermission();
void lookChangePermission();

int main()
{
	int choice = 0;
	
	while(1)
	{
		choice = menu();
		if(choice == 0)
		{
			break;
		}
		else if(choice == 1)
		{
			creatFile();
			pressKey();
		}
		else if(choice == 2)
		{
			writeFile();
			pressKey();
		}
		else if(choice == 3)
		{
			readFile();
			pressKey();
		}
		else if(choice == 4)
		{
			changePermission();
			pressKey();
		}
		else if(choice == 5)
		{
			lookChangePermission();
			pressKey();
		}
	}
}


int menu()
{
	int choice = 0;

	system("clear");
	printf("****************************\n");
	printf("0.exit\n");
	printf("1.creat file\n");
	printf("2.write file\n");
	printf("3.read file\n");
	printf("4.change permission\n");
	printf("5.look(change) permission\n");
	printf("****************************\n");

	printf("Please input your choice(0-5):");
	scanf("%d", &choice);
	while(choice < 0 || choice > 5)
	{
		printf("Wrong! Input again(0-5):");
		scanf("%d", &choice);
	}

	return choice;
}

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

void pressKey()
{
	char c;
	printf("Press any key contiue\n");
	while ((c = getchar()) != EOF && c != '\n');
	c = getchar();
}












