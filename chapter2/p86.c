/*
  I add main function for test.

  Your output should be like this after you running:
  pqy@sda1:~/.../chapter2$ ./a.out 
  The max file can be open: 65536
  
 */


#include "apue.h"
#include <errno.h>
#include <limits.h>

#ifdef OPEN_MAX
static long openmax = OPNE_MAX;
#else
static long openmax = 0;
#endif

#define OPEN_MAX_GUESS 256

long open_max(void)
{
  if (openmax == 0)
    {
      errno = 0;
      if ((openmax = sysconf(_SC_OPEN_MAX)) < 0)
	{
	  if (errno == 0)
	    openmax = OPEN_MAX_GUESS;

	  else
	    err_sys("sysconf error for _SC_OPEN_MAX");
	}
    }

  return (openmax);
}

int main(int argc, char *argv[])
{
  openmax = open_max();
  printf("The max file can be open: %ld\n", openmax);
  
  return 0;
}

