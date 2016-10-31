/*
  Before you can compile this program successfully, please download the source codes of APUE book
from www.apuebook.com, and compile it firstly.

Make sure you have all the necessary dev packages installed before make, otherwise your make will fail.
For example, if you see the following make error:

/usr/bin/ld: cannot find -lbsd

that means you don't have libbsd-dev installed. All you have to do is

sudo apt install libbsd-dev

and then make again.

Usually, you don't have to compile each .c source file individually with gcc. 
Instead, after making some modification, for example, you can just type 'make'. 
'Make' will take care of everything for you.

If you insist on compiling each .c with gcc, you can do, for example, like this:

gcc p81.c -I ../../apue.3e/include/ -L ../../apue.3e/lib/ -lapue

 * -I tells gcc which directory to look for the include file.
 * -L tells it the location of the library directory, and
 * -lapue, tells the name of the library file to look for in that directory.

The output should be like this:
    pqy@sda1:~/.../chapter2$ ./a.out /
    no symbol for ARG_MAX
    ARG_MAX =  2097152
    MAX_CANON defined to be 255
    MAX_CANON =  255

 */


#include <apue.h>
#include <errno.h>
#include <limits.h>

static void pr_sysconf(char *, int);
static void pr_pathconf(char *, char *, int);

int main(int argc, char *argv[])
{
  if (argc != 2)
    err_quit("usage: a.out <directory name>");

#ifdef ARG_MAX
  printf("ARG_MAX defined to be %ld\n", (long)ARG_MAX + 0);
#else
  printf("no symbol for ARG_MAX\n");
#endif

#ifdef _SC_ARG_MAX
  pr_sysconf("ARG_MAX = ", _SC_ARG_MAX);
#else
  printf("no symbol for _SC_ARG_MAX\n");
#endif

#ifdef MAX_CANON
  printf("MAX_CANON defined to be %ld\n", (long)MAX_CANON + 0);
#else
  printf("no symbol for MAX_CANON\n");
#endif

#ifdef _PC_MAX_CANON
  pr_pathconf("MAX_CANON = ", argv[1], _PC_MAX_CANON);
#else
  printf("no symbol for _PC_MAX_CANON\n");
#endif

  exit(0);
}

static void pr_sysconf(char *mesg, int name)
{
  long val;

  fputs(mesg, stdout);
  errno = 0;

  if ((val = sysconf(name)) < 0)
    {
      if (errno != 0)
	{
	  if (errno == EINVAL)
	    fputs(" (not supported)\n", stdout);

	  else
	    err_sys("sysconf error");
	}
      else
	fputs(" (no limit)\n", stdout);
    }

  else
    printf(" %ld\n", val);
}

static void pr_pathconf (char *mesg, char *path, int name)
{
  long val;

  fputs(mesg, stdout);
  errno = 0;
  if ((val = pathconf(path, name)) < 0)
    {
      if (errno != 0)
	{
	  if (errno == EINVAL)
	    fputs(" (not supported)\n", stdout);
	  else
	    err_sys("pathconf error, path = %s", path);
	}

      else
	fputs(" (no limit)\n", stdout);
    }

  else
    printf(" %ld\n", val);
}
