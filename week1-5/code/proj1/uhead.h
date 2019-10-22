#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define UNUMBER 100

struct arg{
	float ave;
	int sum;
};

//func1.c
void show(int *, int);
void urandone(int *, int);
void urandtwo(int *, int *, int);
int usum(int *, int);
void arrToFile(char *, int *, int);
void showfile(char *);
void showFileStartL(char *, int);
void arrToFileStartL(char *, int *, int , int);
//func2.c
struct arg operater(int *, int);
//func3.c
int compar(const void *, const void *);
void syssort(int *, int);
void mysort(int *, int);

