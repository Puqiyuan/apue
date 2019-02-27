/*
	running results:
	~/.../chapter8$ ./a.out 
	normal termination, exit staus = 7
	abnormal termination, signal number = 6
	abnormal termination, signal number = 8
*/

#include <apue.h>
#include <sys/wait.h>
#include "./8.5.c"

int main(int argc, char *argv[])
{
	pid_t pid;
	int status;

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		exit(7);

	if (wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		abort();

	if (wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		status /= 0;
	
	if (wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);
		
	return 0;
}
