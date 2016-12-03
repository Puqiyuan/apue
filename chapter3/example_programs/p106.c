/*
  page number in the paper book: 72

  the output should be like this:
  pqy@sda1:~/.../chapter3$ ./a.out 
  abcdefghijklmn
  abcdefghijklmn
  dfsdfjwi
  dfsdfjwi
  !@#$$#@$%^%$$
  !@#$$#@$%^%$$

 */
#include "apue.h"

#define BUFFSIZE 4096

int main(void)
{
  int n;
  char buf[BUFFSIZE];

  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    if (write(STDOUT_FILENO, buf, n) != n)
      err_sys("write error");

  if (n < 0)
    err_sys("read error");

    
  exit(0);
}
