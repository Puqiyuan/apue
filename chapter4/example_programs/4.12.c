/*
  running result:
  ~/.../example_programs$ ls -l bar foo
  -rw------- 1 pqy7172 pqy7172 0 Jul 25 18:23 bar
  -rw-rw-rw- 1 pqy7172 pqy7172 0 Jul 25 18:23 foo
  ~/.../example_programs$ gcc 4.12.c  -I ~/APUE/include/ -L ~/APUE/lib/ -lapue
  ~/.../example_programs$ ./a.out 
  ~/.../example_programs$ ls -l bar foo
  -rw-r--r-- 1 pqy7172 pqy7172 0 Jul 25 18:23 bar
  -rw-rwSrw- 1 pqy7172 pqy7172 0 Jul 25 18:23 foo
  ~/.../example_programs$
*/

#include <apue.h>

int main(int argc, char *argv[])
{
	struct stat statbuf;

	if (stat("foo", &statbuf) < 0) // first get the stat struct of foo file
		err_sys("stat error for foo");

	// turn on set-group-ID(S_ISGID) and turn off group-execute(S_IXGRP)
	if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0) // the member st_mode in statbuf is used to keep the original permissions
		err_sys("chmod error for foo");

	// set absolute mode to rw-r--r-- for "bar" file
	if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) // Comparing with foo file, here we didn't use struct stat of foo file to saved original permissions but set absolute permissions.
		err_sys("chmod error for bar");
	
    exit(0);
}
