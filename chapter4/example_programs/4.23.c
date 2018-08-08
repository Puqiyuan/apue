/*
  running result:
  ~/.../example_programs$ pwd
  /home/pqy7172/APUE/chapter4/example_programs
  ~/.../example_programs$ ./a.out 
  chdir to /tmp succeeded
  ~/.../example_programs$ pwd
  /home/pqy7172/APUE/chapter4/example_programs
*/

#include <apue.h>

int main(int argc, char *argv[])
{
	if (chdir("/tmp") < 0)
		err_sys("chdir failed");
	printf("chdir to /tmp succeeded\n");
	
    exit(0);
}
