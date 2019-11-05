#include "my.h"

static void __attribute__((constructor)) before_main()
{
	printf("Running before main\n");
}

static void callback1()
{
	printf("Running after main1\n");
}

static void callback2()
{
	printf("Running after main2\n");
}

static void callback3()
{
	printf("Running after main3\n");
}

int main()
{
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	printf("test1: pid=%d, ppid=%d\n", getpid(), getppid());
	sleep(2);
}
