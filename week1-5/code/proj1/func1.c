#include "uhead.h"

//one rand arr//
void urandone(int *a, int n){
	int i;
	srand((int)time(0));
	for(i = 0; i < n; i++){
		a[i] = 1 + (int)(1000.0 * rand()/(RAND_MAX + 1.0));
	}
	arrToFile("randdata.txt", a, n);
}

//two rand arr
void urandtwo(int *a,int *b, int n){
	int i;
	srand((int)time(0));
	for(i = 0; i < n; i++){
		a[i] = 1 + (int)(1000.0 * rand()/(RAND_MAX + 1.0));
		b[i] = a[i];
	}
	arrToFile("randdata.txt", a, n);
}

//sum of arr
int usum(int *a, int n){
	int i;
	int sum;
	for(i = 0; i < n; i++){
		sum += a[i];
	}
	return sum;
}

//print value of arr
void show(int *a, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("a[%d]=%d \n", i, a[i]);	
	}
}

//arr to file
void arrToFile(char *fileName, int *a, int n){
	int flags = O_CREAT | O_TRUNC | O_WRONLY;
	int fddes;
	int z;
	int length;	

	char b[5];
	int i = 0;

	fddes = open(fileName,flags,0644);
	if(fddes < 0){
		printf("open_error\n");
		exit(1);	
	}

	for(i = 0; i < n; i++){

		if(a[i]/1000 != 0)
			length = 5;
		else if(a[i]/100 != 0)
			length = 4;
		else if(a[i]/10 != 0)
			length = 3;
		else
			length = 2;

		sprintf(b,"%d",a[i]);
		strcat(b,",");

		z = write(fddes,b,length);
		if(z < 0){
			printf("write_error");
			exit(1);	
		}
	}
	close(fddes);
}

//get info from file
void showfile(char *fileName){
	int fdsrc;
	int i,j = 0,nbytes;
	char buf[20];

	fdsrc = open(fileName, O_RDONLY);
	if(fdsrc < 0){ 
			printf("open_error");
			exit(1);	
	}

	while(nbytes = read(fdsrc,buf,20) > 0){
		for(i=0;i<20;i++){
			if(buf[i] == '.')
				break;

			printf("%c",buf[i]);

			if(buf[i] == ','){
				j++;
				if(j==10){
					j = 0;
					printf("\n");
				}
			}

			buf[i] = '.';
		}
	}
}

//get info from file
void showFileStartL(char *fileName, int l){
	int fdsrc,currpos;
	int i,j = 0,nbytes;
	char buf[20];
	
	fdsrc = open(fileName, O_RDONLY);
	if(fdsrc < 0){ 
			printf("open_error");
			exit(1);	
	}

	currpos = lseek(fdsrc, l, SEEK_SET);
	if(currpos < 0){ 
			printf("lseek_error");
			exit(1);	
	}
	
	while(nbytes = read(fdsrc,buf,20) > 0){
		for(i=0;i<20;i++){
			if(buf[i] == '.')
				break;

			printf("%c",buf[i]);

			if(buf[i] == ','){
				j++;
				if(j==10){
					j = 0;
					printf("\n");
				}
			}

			buf[i] = '.';
		}
	}
	printf("\n");
}


//change file
void arrToFileStartL(char *fileName, int *a, int n, int l){
	int flags = O_CREAT | O_WRONLY;
	int fddes,currpos;
	int z;
	int length;

	char b[5];
	int i = 0;


	fddes = open(fileName,flags,0644);
	if(fddes < 0){
		printf("open_error\n");
		exit(1);	
	}

	currpos = lseek(fddes, l, SEEK_SET);
	if(currpos < 0){ 
			printf("lseek_error");
			exit(1);	
	}

	for(i = 0; i < n; i++){

		if(a[i]/1000 != 0)
			length = 5;
		else if(a[i]/100 != 0)
			length = 4;
		else if(a[i]/10 != 0)
			length = 3;
		else
			length = 2;

		sprintf(b,"%d",a[i]);
		strcat(b,",");

		z = write(fddes,b,length);
		if(z < 0){
			printf("write_error");
			exit(1);	
		}
	}
	close(fddes);
}
