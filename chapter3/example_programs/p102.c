//page number in paper book: 68
/*
  the output should be like this:
  pqy@sda1:~/.../bin$ ./p102
  pqy@sda1:~/.../bin$ ls -sl file.hole 
  8 -rw-r--r-- 1 pqy pqy 16394 Dec  3 13:42 file.hole
  pqy@sda1:~/.../bin$ od -c file.hole 
  0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
  0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
  *
  0040000   A   B   C   D   E   F   G   H   I   J
  0040012

  The explanation in the book on the page 68.
 */



#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
  int fd;
  
  if ((fd = creat("file.hole", FILE_MODE)) < 0)
    err_sys("create error");

  if (write(fd, buf1, 10) != 10)
    err_sys("buf1 write error");

  if (lseek(fd, 16384, SEEK_SET) == -1)
    err_sys("lseek error");

  if (write(fd, buf2, 10) != 10)
    err_sys("buf2 write error");
    
  exit(0);
}

