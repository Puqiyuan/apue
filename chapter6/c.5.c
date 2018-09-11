#include <apue.h>
#include <shadow.h>

int main(int argc, char *argv[])
{
	struct spwd *ptr;

	if ((ptr = getspnam("pqy7172")) == NULL)
		err_sys("getspnam error");
	printf("sp_pwdp = %s\n", ptr->sp_pwdp == NULL ||
				 ptr -> sp_pwdp[0] == 0 ? "(null)": ptr->sp_pwdp);
	
	exit(0);
}
