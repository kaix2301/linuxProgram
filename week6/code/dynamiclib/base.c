#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void init(int *a, int n)
{
	int i;
	srand((int)time(0));
	for(i = 0; i < n; i++){
		a[i] = 1 + (int)(1000.0 * rand()/(RAND_MAX + 1.0));
	}
}

void show(int *a, int n)
{
	int i;
	for(i=0;i<n;i++)
	{	
		if(i%4 == 0)
			printf("\n");
		printf("%4d : %4d", i+1, a[i]);
	}
}
