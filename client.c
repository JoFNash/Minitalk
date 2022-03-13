#include "includes/minitalk.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void client(pid_t ppid, char *message)
{
	int	i;

	i = 128;

	while (*message)
	{
		while (i != 2)
		{
			if (i & *message)
			{
				kill(ppid, SIGUSR1);
			}
			else
			{
				kill(ppid, SIGUSR1);
			}
			i /= 2;
		}
		message++;
	}
}

// int	main(int argc, char *argv[])
// {
// 	pid_t	ppid;
// 	char	*message;

// 	if (argc != 3)
// 	{
// 		printf("Error! Enter 1) ppid 2) message");
// 		exit(EXIT_FAILURE);
// 	}
// 	ppid = (pid_t)ft_atoi(argv[1]);
// 	message = argv[2];
// 	client(ppid, message);
// 	return (0);
// }


int main(int argc, char **argv)
{
	int k;
	k = atoi(argv[1]);
	printf("%d\n", k);
	kill(k, SIGUSR1);
}