#include <stdio.h>
#include "mylib.h"

int main()
{
	int a[8];
	init(a,8);
	show(a,8);
	printf("\nsum=%d\n",sum(a,8));
	printf("max=%d\n",max(a,8));
	return 0;
}
