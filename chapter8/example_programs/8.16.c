#include "apue.h"
#include <sys/wait.h>

char *env_init[] = { "USER=unknow", "PATH=/tmp", NULL };

int main(int argc, char *argv[])
{
	pid_t pid;

	if ((pid = fork()) < 0)
			err_sys("fork error");
	else if (pid == 0)
		{
			if (execle("/home/pqy7172/APUE/bin/8.17", "echoall",
								 "myargv1", "MY ARG2", (char*)0, env_init) < 0)
				err_sys("execle error");
				
		}
	if (waitpid(pid, NULL, 0) < 0)
		err_sys("wait error");

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		{
			if (execlp("8.17", "echoall", "only 1 arg", (char*)0) < 0)
				err_sys("execlp error");
		}
	
	return 0;
}

