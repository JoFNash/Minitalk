#include "includes/minitalk.h"

# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

#include <stdio.h>
void	run(int sig, siginfo_t *info, void *other)
{

	printf("sss\n");
	
	
	
	// static int	bit;
	// static int	res_char;

	// (void)other;
	// res_char = add_bit(sig, &bit, &res_char);
	// if (bit == 8)
	// {
	// 	if (res_char != 0)
	// 		write(1, &res_char, 1);
	// 	else
	// 		if (kill(info->si_pid, SIGUSR1))
	// 			error_exit("\n|error send SIGUSR1|\n");
	// 	res_char = 0;
	// 	bit = 0;
	// }
}

void	set_sigaction_struct(struct sigaction *sa, sigset_t non_mask)
{
	sa->sa_handler = 0;
	sa->sa_flags = SA_SIGINFO;
	sa->sa_mask = non_mask;
	sa->sa_sigaction = run;
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			non_mask;

	// signal(SIGUSR1, run);
	if (sigemptyset(&non_mask) == -1 || \
		sigaddset(&non_mask, SIGINT) == -1 || \
		sigaddset(&non_mask, SIGQUIT) == -1)
		printf("\n| error sigaddset() |\n");
	set_sigaction_struct(&sa, non_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || \
		sigaction(SIGUSR2, &sa, NULL) == -1)
		printf("\n| error sigaction() |\n");
	printf("%d\n", getpid());
	while (1)
	{
		pause();
	}
}