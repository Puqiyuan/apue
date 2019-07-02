#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void sig_alrm(int signo)
{
	
}

unsigned int sleep1(unsigned int seconds)
{
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		return(seconds);
	alarm(seconds);
	pause();
	return(alarm(0));
}

int main(int argc, char *argv[])
{
	printf("I'm going to sleep 2 seconds:\n");
	sleep1(2);
	printf("I'm wake\n\n");
	printf("Another 5 seconds sleep:\n");
	sleep1(5);
	
	return 0;
}
