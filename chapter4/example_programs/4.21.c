/*
  test results:
  ~/.../example_programs$ ls -l changemod times 
  -rw-r--r-- 1 pqy7172 root 13312 Jul 31 23:26 changemod
  -rw-r--r-- 1 pqy7172 root 13824 Jul 31 23:26 times
  ~/.../example_programs$ ls -lu changemod times 
  -rw-r--r-- 1 pqy7172 root 13312 Jul 31 23:28 changemod
  -rw-r--r-- 1 pqy7172 root 13824 Jul 31 23:28 times
  ~/.../example_programs$ date
  Tue Jul 31 23:30:40 HKT 2018
  ~/.../example_programs$ ./a.out changemod times 
  ~/.../example_programs$ ls -l changemod times 
  -rw-r--r-- 1 pqy7172 root 0 Jul 31 23:26 changemod
  -rw-r--r-- 1 pqy7172 root 0 Jul 31 23:26 times
  ~/.../example_programs$ ls -lu changemod times 
  -rw-r--r-- 1 pqy7172 root 0 Jul 31 23:28 changemod
  -rw-r--r-- 1 pqy7172 root 0 Jul 31 23:28 times
  ~/.../example_programs$ ls -lc changemod times 
  -rw-r--r-- 1 pqy7172 root 0 Jul 31 23:30 changemod
  -rw-r--r-- 1 pqy7172 root 0 Jul 31 23:30 times
  ~/.../example_programs$
*/

#include <apue.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int i, fd;
	struct stat statbuf;
	struct timespec times[2];

	for (i = 1; i < argc; i++)
		{
			if (stat(argv[i], &statbuf) < 0)
				{
					err_ret("%s: stat error", argv[i]);
					continue;
				}
			if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0)
				{
					err_ret("%s: open error", argv[i]);
					continue;
				}
			times[0] = statbuf.st_atim; // last data access timestamp
			times[1] = statbuf.st_mtim; // last data modification timestamp
			if (futimens(fd, times) < 0)
				err_ret("%s: futimens error", argv[i]);
			close(fd);
		}
	
    exit(0);
}
