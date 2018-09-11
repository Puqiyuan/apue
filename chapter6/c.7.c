/*
	running result:
	~/.../chapter6$ ./a.out 
	Tue Sep 11 22:31:23 HKT 2018
	~/.../chapter6$ TZ=US/Mountain ./a.out 
	Tue Sep 11 08:31:40 MDT 2018
	~/.../chapter6$ TZ=Japan ./a.out 
	Tue Sep 11 23:31:52 JST 2018
*/

#include <apue.h>
#include <time.h>

int main(int argc, char *argv[])
{
	time_t caltime;
	struct tm *tm;
	char line[MAXLINE];

	if ((caltime = time(NULL)) == -1)
		err_sys("time error");
	if ((tm = localtime(&caltime)) == NULL)
		err_sys("localtime error");
	if (strftime(line, MAXLINE, "%a %b %d %X %Z %Y\n", tm) == 0)
		err_sys("strfime error");
	fputs(line, stdout);
	
	exit(0);
}
