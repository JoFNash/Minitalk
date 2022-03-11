#include "includes/minitalk.h"

#include <stdlib.h>
#include <stdio.h>


int	main(void)
{
	pid_t myPid;

	myPid = getpid();
	printf("This process ID of thus programm is %d\n", getpid());
	return (0);
}