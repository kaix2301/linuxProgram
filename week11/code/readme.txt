my.h为常用头文件

test1.c通过fork派生子进程，然后在后台运行，用ps命令查看进程情况
test2.c在test1.c基础上利用getchar让子进程暂停运行，父进程等待子进程，用ps命令查看进程情况
test3.c在test2.c基础上，输出了子进程退出原因
test3.c在test3.c基础上变为派生两个子进程，
	a.通过waitpid等待子进程2结束，输出其退出原因
	b.通过wait等待子进程，通过返回值判断子进程结束的先后

tforktest.c先写一个pr_exit(int status, pid_t pid)函数，实现进程退出原因判断和退出码输出，然后主函数派生子进程，调用该函数

sh文件夹中，6-8.c中实现了守护进程的验证，每十秒向文件写一条数据
filepoint文件夹中，test.c验证了不同子进程是否共享文件指针，两个子进程都往同一个文件里写数据，如果共享文件指针，则不同进程写入的数据均在文件中，若不共享文件指针，则会有数据被覆盖的情况。
guandao文件夹中，gdtest.c实现了通过管道读写字符串。

查看进程情况的命令:
//ps -aux | grep test1
//ps -ef | grep test1
