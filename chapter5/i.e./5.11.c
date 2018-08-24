/*
  running result:
  ~/.../i.e.$ ./a.out 
  enter any character

  one line to standard error
  stream = stdin, line buffered, buffer size = 1024
  stream = stdout, line buffered, buffer size = 1024
  stream = stderr, unbuffered, buffer size = 1
  stream = /etc/passwd, fully buffered, buffer size = 4096
  ~/.../i.e.$ ./a.out < /etc/group > std.out 2> std.err
  ~/.../i.e.$ cat std.err 
  one line to standard error
  ~/.../i.e.$ cat std.out 
  enter any character
  stream = stdin, fully buffered, buffer size = 4096
  stream = stdout, fully buffered, buffer size = 4096
  stream = stderr, unbuffered, buffer size = 1
  stream = /etc/passwd, fully buffered, buffer size = 4096
*/

#include <apue.h>

void pr_stdio(const char *, FILE *);
int is_unbuffered(FILE *);
int is_linebuffered(FILE *);
int buffer_size(FILE *);

int main(int argc, char *argv[])
{
	FILE *fp;

	fputs("enter any character\n", stdout);
	if (getchar() == EOF)
		err_sys("getchar error");
	fputs("one line to standard error\n", stderr);

	pr_stdio("stdin", stdin);
	pr_stdio("stdout", stdout);
	pr_stdio("stderr", stderr);

	if ((fp = fopen("/etc/passwd", "r")) == NULL)
		err_sys("fopen error");

	if (getc(fp) == EOF)
		err_sys("getc error");
	pr_stdio("/etc/passwd", fp);
	
    exit(0);
}

void pr_stdio(const char *name, FILE *fp)
{
	printf("stream = %s, ", name);
	if (is_unbuffered(fp))
		printf("unbuffered");
	else if (is_linebuffered(fp))
		printf("line buffered");
	else
		printf("fully buffered");
	printf(", buffer size = %d\n", buffer_size(fp));
}

#if defined(_IO_UNBUFFERED)

int is_unbuffered(FILE *fp)
{
	return(fp->_flags & _IO_UNBUFFERED);
}

int is_linebuffered(FILE *fp)
{
	return(fp->_flags & _IO_LINE_BUF);
}

int buffer_size(FILE *fp)
{
	return(fp->_IO_buf_end - fp->_IO_buf_base);
}

#elif defined(_SNBF)

int is_unbuffered(FILE *fp)
{
	return(fp->_flags & __SNBF);
}

int is_linebuffered(FILE *fp)
{
	return(fp->_flags & __SLBF);
}

int buffer_size(FILE *fp)
{
	return(fp->_bf._size);
}

#elif defined(_IONBF)

#ifdef _LP64
#define _flag __pad[4]
#define _ptr __pad[1]
#define _base __pad[2]
#endif

int is_unbuffered(FILE *fp)
{
	return(fp->_flag & _IONBF);
}

int is_linebuffered(FILE *fp)
{
	return(fp->_flag & _IOLBF);
}

int buffer_size(FILE *fp)
{
#ifdef _LP64
	return(fp->_base - fp->_ptr);
#else
	return(BUFSIZ);
#endif
}

#else

#error unknown stdin implementation

#endif
