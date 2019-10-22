#include "mylib.h"

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
