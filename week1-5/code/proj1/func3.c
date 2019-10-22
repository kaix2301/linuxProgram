#include "uhead.h"

int compar(const void *a, const void *b){
	int *aa = (int *)a, *bb = (int *)b;
	if(*aa > *bb)
		return 1;
	if(*aa == *bb)
		return 0;
	if(*aa < *bb)
		return -1;
}

void syssort(int *a, int n){
	struct timeval tv1, tv2;
	struct timezone tz;
	gettimeofday(&tv1, &tz);
	qsort(a, n, sizeof(int), compar);
	gettimeofday(&tv2, &tz);
	arrToFile("syssort.txt", a, n);
	printf("syssort-runtime:%ld \n", tv2.tv_usec - tv1.tv_usec);
}

void mysort(int *a, int n){
	int i = 0, j = 0, buf = 0;

	struct timeval tv1, tv2;
	struct timezone tz;
	gettimeofday(&tv1, &tz);

	//mao pao pai xu
	for(i = 0; i < n; i++){
		for(j = 0; j < n-1-i; j++){
			if(a[j] > a[j + 1]){
				buf = a[j];
				a[j] = a[j + 1];
				a[j + 1] = buf;
			}		
		}	
	}

	gettimeofday(&tv2, &tz);
	arrToFile("mysort.txt", a, n);
	printf("mysort-runtime:%ld \n", tv2.tv_usec - tv1.tv_usec);
}
