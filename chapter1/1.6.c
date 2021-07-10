#include "apue.h"

int main(int argc, char *argv[])
{
	printf("helllo world from process ID %ld\n", (long)getpid());
	
    return 0;
}
