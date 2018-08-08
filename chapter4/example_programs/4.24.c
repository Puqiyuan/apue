/*
  running result:
  ~/.../example_programs$ pwd
  /home/pqy7172/APUE/chapter4/example_programs
  ~/.../example_programs$ ./a.out 
  cwd = /home/pqy7172
*/

#include <apue.h>

int main(int argc, char *argv[])
{
	char *ptr;
	size_t size;

	if (chdir("/home/pqy7172") < 0)
		err_sys("chdir failed");

	ptr = path_alloc(&size);
	if (getcwd(ptr, size) == NULL)
		err_sys("getcwd failed");

	printf("cwd = %s\n", ptr);
	
    exit(0);
}
