#include "uhead.h"

struct arg operater(int *a, int n){
	struct arg myarg;
	int i;
	myarg.sum = 0;
	myarg.ave = 0;
	for(i = 0; i < n; i++){
		myarg.sum += a[i];	
	}
	myarg.ave = ((float)myarg.sum)/n;
	return myarg;
}
