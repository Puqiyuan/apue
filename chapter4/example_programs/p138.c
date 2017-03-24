/*
  page number on book: 105
  test result:
  pqy@sda1:~/.../bin$ umask 
  0022
  pqy@sda1:~/.../bin$ ./p138
  pqy@sda1:~/.../bin$ ls -l foo bar
  -rw------- 1 pqy pqy 0 Mar 24 23:02 bar
  -rw-rw-rw- 1 pqy pqy 0 Mar 24 23:02 foo
 */

#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char *argv[])
{
  umask(0);

  if (creat("foo", RWRWRW) < 0)
    err_sys("create error for foo");

  umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

  if (creat("bar", RWRWRW) < 0)
    err_sys("create error for bar");


  exit(0);
}

