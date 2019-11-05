验证不同方式调用可执行程序的差别
	test.c输出自己的pid和ppid
	call1.c用system方式调用test
	call2.c用exec方式调用test
验证父进程和子进程执行顺序以及是否共享堆栈
	forktest.c开辟新进程通过输出和修改数据进行验证
