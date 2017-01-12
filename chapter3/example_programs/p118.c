//the page number in paper book is: 85
/*
  the output should be like these:
  pqy@sda1:~/.../chapter3$ ./a.out 0 < /dev/tty
  read only
  pqy@sda1:~/.../chapter3$ ./a.out 1 > temp.foo 
  pqy@sda1:~/.../chapter3$ cat temp.foo 
  write only
  pqy@sda1:~/.../chapter3$ ./a.out 2 2>>temp.foo 
  write only, append
  pqy@sda1:~/.../chapter3$ ./a.out 5 5<>temp.foo
  read write

 */


#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
  int val;

  if (argc != 2)
    err_quit("usage: a.out <descriptor#>");

  if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
    err_sys("fcntl error for fd %d", atoi(argv[1]));

  switch (val & O_ACCMODE)
    {
    case O_RDONLY:
      printf ("read only");
      break;

    case O_WRONLY:
      printf("write only");
      break;

    case O_RDWR:
      printf("read write");
      break;

    default:
      err_dump("unknown access mode");
    }

  if (val & O_APPEND)
    printf(", append");

  if (val & O_NONBLOCK)
    printf(", non blocking");

  if (val & O_SYNC)
    printf(", synchronous writes");

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
  if (val & O_FSYNC)
    printf(", synchronous writes");

#endif

  printf("\n");
    
  exit(0);
}

