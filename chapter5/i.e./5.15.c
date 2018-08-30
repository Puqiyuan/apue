/*
  test result:
  ~/.../i.e.$ ./a.out 
  initial buffer contents: 
  before flush: 
  after fflush: hello, world
  len of string in buf = 12
  after fseek: bbbbbbbbbbbbhello, world
  len of string in buf = 24
  after fclose: hello, worldcccccccccccccccccccccccccccccccccc
  len of string in buf = 46
*/

#include <apue.h>

#define BSZ 48

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[BSZ];

	memset(buf, 'a', BSZ-2);
	buf[BSZ - 2] = '\0';
	buf[BSZ - 1] = 'x';
	if ((fp = fmemopen(buf, BSZ, "w+")) == NULL)
		err_sys("fmemopen failed");
	printf("initial buffer contents: %s\n", buf);
	fprintf(fp, "hello, world");
	printf("before flush: %s\n", buf);
	fflush(fp);
	printf("after fflush: %s\n", buf);
	printf("len of string in buf = %ld\n", (long)strlen(buf));

	memset(buf, 'b', BSZ - 2);
	buf[BSZ -2 ] = '\0';
	buf[BSZ - 1] = 'X';
	fprintf(fp, "hello, world");
	fseek(fp, 0, SEEK_SET);
	printf("after fseek: %s\n", buf);
	printf("len of string in buf = %ld\n", (long)strlen(buf));

	memset(buf, 'c', BSZ - 2);
	buf[BSZ - 2] = '\0';
	buf[BSZ - 1] = 'X';
	fprintf(fp, "hello, world");
	fclose(fp);
	printf("after fclose: %s\n", buf);
	printf("len of string in buf = %ld\n", (long)strlen(buf));
	
    exit(0);
}
