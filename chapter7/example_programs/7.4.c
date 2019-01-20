/*
	running results:
	~/.../chapter7$ ./a.out argu1 argu2
	argv[0]: ./a.out
	argv[1]: argu1
	argv[2]: argu2
*/

#include <apue.h>

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);
	
	return 0;
}
