/*
	test result:
	~/.../chapter8$ ./a.out 
	a write to stdout
	before fork
	pid = 4056, glob = 7, var = 89
	pid = 4055, glob = 6, var = 88
	~/.../chapter8$ ./a.out > temp.out
	~/.../chapter8$ cat temp.out 
	a write to stdout
	before fork
	pid = 4078, glob = 7, var = 89
	before fork
	pid = 4077, glob = 6, var = 88
*/

#include <apue.h>

int globvar = 6;
char buf[] = "a write to stdout\n";

int main(int argc, char *argv[])
{
	int var;
	pid_t pid;

	var = 88;
	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
		err_sys("write error");
	printf("before fork\n");

	if ((pid = fork()) < 0)
		{
			err_sys("fork error");
		}
	else if (pid == 0) // child
		{
			globvar++;
			var++;
		}
	else
		sleep(2); // parent

	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
	
	return 0;
}

