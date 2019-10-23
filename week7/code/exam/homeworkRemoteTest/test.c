#include "mylib.h"

int main()
{
	int choice = 0;
	
	while(1)
	{
		choice = menu_1();
		if(choice == 0)
		{
			break;
		}
		else if(choice == 1)
		{
			creatFile_1();
			pressKey_1();
		}
		else if(choice == 2)
		{
			writeFile_1();
			pressKey_1();
		}
		else if(choice == 3)
		{
			readFile_1();
			pressKey_1();
		}
		else if(choice == 4)
		{
			changePermission_1();
			pressKey_1();
		}
		else if(choice == 5)
		{
			lookChangePermission_1();
			pressKey_1();
		}
	}
}
