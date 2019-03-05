#include "apue.h"
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		{
			if (execl("/home/pqy7172/APUE/chapter8/example_programs/testinterp", "testinterp", "myarg1", "MY ARG2",
								(char *)0) < 0)
				err_sys("execl error");
		}
	if (waitpid(pid, NULL, 0) < 0)
		err_sys("waitpid error");
	
	return 0;
}
