/*
  page number in paper book: 103
  the test result:
  pqy@sda1:~/.../bin$ ls -l p137 
  -rwxr-xr-x 1 pqy pqy 13456 Mar 24 12:12 p137*
  pqy@sda1:~/.../bin$ ./p137 ./p137 
  read access OK
  open for reading OK
  pqy@sda1:~/.../bin$ ls -l /etc/shadow
  -rw-r----- 1 root shadow 1273 Nov 10 01:00 /etc/shadow
  pqy@sda1:~/.../bin$ ./p137 /etc/shadow
  access error for /etc/shadow: Permission denied
  open error for /etc/shadow: Permission denied
  pqy@sda1:~/.../bin$ su
  Password: 
  root@sda1:.../bin# chown root ./p1
  p101  p102  p106  p118  p130  p137  
  root@sda1:.../bin# chown root ./p137 
  root@sda1:.../bin# ls -l ./p137
  -rwxr-xr-x 1 root pqy 13456 Mar 24 12:12 ./p137
  root@sda1:.../bin# chmod u+s ./137
  chmod: cannot access ‘./137’: No such file or directory
  root@sda1:.../bin# chmod u+s ./p137
  root@sda1:.../bin# ls -l ./p137
  -rwsr-xr-x 1 root pqy 13456 Mar 24 12:12 ./p137
  root@sda1:.../bin# exit
  exit
  pqy@sda1:~/.../bin$ ./p137 /etc/shadow
  access error for /etc/shadow: Permission denied
  open for reading OK
 */



#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
    err_quit("usage: a.out <path name>");

  if (access(argv[1], R_OK) < 0)
    err_ret("access error for %s", argv[1]);

  else
    printf("read access OK\n");

  if (open(argv[1], O_RDONLY) < 0)
    err_ret("open error for %s", argv[1]);

  else
    printf("open for reading OK\n");
  
  exit(0);
}

