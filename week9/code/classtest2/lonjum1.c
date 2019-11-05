#include "my.h"
#include <setjmp.h>

static jmp_buf g_stack_env;

static void fun1(void);
static void fun2(void);

int main()
{
	if(0 == setjmp(g_stack_env))
	{
		printf("Normal flow\n");
		fun1();
	}
	else
	{
		printf("Long jump flow\n");
	}

	return 0;
}

static void fun1(void)
{
	printf("Enter fun1\n");
	fun2();
}

static void fun2(void)
{
	printf("Enter fun2\n");
	longjmp(g_stack_env, 1);
	printf("Leave fun2\n");
}
