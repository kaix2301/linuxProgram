#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "dylib.h"

int main()
{
	int a[8];

	void *hd;
	char *error;
	void (*f1)();
	int (*f2)(), (*f3)(), (*f4)();
	
	hd = dlopen("../../dynamiclib/libdylib.so", RTLD_LAZY);
	if(!hd){
		fprintf(stderr, "%s\n", dlerror());	
		exit(1);
	}

	f1 = dlsym(hd, "init");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", dlerror());	
		exit(1);
	}
	
	f2 = dlsym(hd, "show");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", dlerror());	
		exit(1);
	}

	f3 = dlsym(hd, "sum");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", dlerror());	
		exit(1);
	}

	f4 = dlsym(hd, "max");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", dlerror());	
		exit(1);
	}

	f1(a,8);
	f2(a,8);
	printf("\nsum=%d\n",f3(a,8));
	printf("max=%d\n",f4(a,8));
	return 0;
}
