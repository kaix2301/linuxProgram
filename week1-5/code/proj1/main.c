#include "uhead.h"

int main(){

	int a[UNUMBER];
	int b[UNUMBER];
	int arr[10] = {100,100,100,100,100,100,100,100,100,100};
	struct arg myarg;

	printf("=============================================\n");

	printf("----------------before sort------------------\n");
	urandtwo(a, b, UNUMBER);
	//urandone(a, UNUMBER);
	showfile("randdata.txt");

	printf("------------------sorting--------------------\n");
	syssort(a, UNUMBER);
	mysort(b, UNUMBER);
	
	printf("----------------after sort-------------------\n");
	showfile("mysort.txt");

	printf("----------------change from 200---------------\n");
	arrToFileStartL("mysort.txt", arr, 10 , 200);
	printf("------------  ----show from 150---------------\n");
	showFileStartL("mysort.txt", 150);

	printf("-----------------sum/ave---------------------\n");
	myarg = operater(a, UNUMBER);
	printf("sum=%d, ave=%f \n", myarg.sum, myarg.ave);

	printf("=============================================\n");
}
