/*
  running results:
  ~/.../example_programs$ ./a.out /home/ /dev/tty[01] /dev/sda1 
  /home/: dev = 8/1
  /dev/tty0: dev = 0/6 (character) rdev = 4/0
  /dev/tty1: dev = 0/6 (character) rdev = 4/1
  /dev/sda1: dev = 0/6 (block) rdev = 8/1
  ~/.../example_programs$ ls -l /home/ /dev/tty[01] /dev/sda1 
  brw-rw---- 1 root    disk 8, 1 Aug  9 19:37 /dev/sda1
  crw--w---- 1 root    tty  4, 0 Aug  9 19:37 /dev/tty0
  crw------- 1 pqy7172 tty  4, 1 Aug  9 19:37 /dev/tty1
*/

#include <apue.h>
#ifdef SOLARIS
#include <sys/mkdev.h>
#endif
#include <sys/sysmacros.h>

int main(int argc, char *argv[])
{
	int i;
	struct stat buf;

	for (i = 1; i < argc; i++)
		{
			printf("%s: ", argv[i]);
			if (stat(argv[i], &buf) < 0) // get file status
				{
					err_ret("stat error");
					continue;
				}

			printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));// return device ID

			if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
				{
					printf(" (%s) rdev = %d/%d", (S_ISCHR(buf.st_mode)) ? "character" : "block", major(buf.st_rdev), minor(buf.st_rdev));
				}
			printf("\n");
		}
	
    exit(0);
}

