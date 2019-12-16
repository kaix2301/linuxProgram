#include "my.h"

int sum;

void *fun(int n)
{
	int i = 0;
	sum = 0;
	for(i=0; i<=n; i++)
	{
		sum += i;
	}
	pthread_exit((void *)sum);
}

int main()
{
	pthread_t tid[4];
	int ret[4], i,n, v[4];
	for(i=0; i<4; i++)
	{
		n = (i+1)*100;
		ret[i] = pthread_create(&tid[i], NULL, fun, n);
		if(ret[i] != 0)
		{
			perror("failed!\n");
		}
		pthread_join(tid[i], (void *)v[i]);
		printf("0 to %d sum : %d", n, (int)v[i]);
	}
	return 0;
}
