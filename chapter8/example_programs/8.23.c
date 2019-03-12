#include "apue.h"
#include <sys/wait.h>
#include "8.22.c"

int main(int argc, char *argv[])
{
	int status;

	if (status = system("date") < 0)
		err_sys("system() error");

	pr_exit(status);

	if ((status == system("nosuchcommand")) < 0)
		err_sys("system() error");

	pr_exit(status);

	if ((status = system("who; exit 44")) < 0)
		err_sys("system() error");

	pr_exit(status);
	
	return 0;
}
