/*
  test result:
  
  pqy@sda1:~/.../bin$ ls bar foo -l
  -rw------- 1 pqy pqy 0 Apr 11 12:52 bar
  -rw-rw-rw- 1 pqy pqy 0 Apr 11 12:52 foo
  pqy@sda1:~/.../bin$ ./p141
  pqy@sda1:~/.../bin$ ls bar foo -l
  -rw-r--r-- 1 pqy pqy 0 Apr 11 12:52 bar
  -rw-rwSrw- 1 pqy pqy 0 Apr 11 12:52 foo
*/


#include "apue.h"

int main(int argc, char *argv[])
{
  
  struct stat statbuf;

  if (stat("foo", &statbuf) < 0)
    err_sys("stat error for foo");

  if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
    err_sys("chmod error for foo");

  if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
    err_sys("chmod error for bar");
  
  return 0;
}

