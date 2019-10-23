#include <stdio.h>
#include <stdlib.h>

int menu_1()
{
	int choice = 0;

	system("clear");
	printf("*******************************\n");
	printf("*  0.exit                     *\n");
	printf("*  1.creat file               *\n");
	printf("*  2.write file               *\n");
	printf("*  3.read file                *\n");
	printf("*  4.change permission        *\n");
	printf("*  5.look(change) permission  *\n");
	printf("*******************************\n");

	printf("Please input your choice(0-5):");
	scanf("%d", &choice);
	while(choice < 0 || choice > 5)
	{
		printf("Wrong! Input again(0-5):");
		scanf("%d", &choice);
	}
	printf("-------------------------------\n");
	return choice;
}

void pressKey_1()
{
	char c;
	printf("Press any key contiue\n");
	while ((c = getchar()) != EOF && c != '\n');
	c = getchar();
}
