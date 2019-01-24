/*
	test result:
	~/.../exercise$ gcc 7.1.c 
	~/.../exercise$ ./a.out 
	hello, world!
	~/.../exercise$ echo $?
	14
 */

#include <stdio.h>
void main(int argc, char *argv[])
{
	printf("hello, world!\n");
}
