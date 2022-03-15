#include "includes/minitalk.h"

# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
#include "libft/libft.h"
#include <stdio.h>

int		add_bit(int signum , int *bit, int *res_char)
{
	if (signum == SIGUSR1)
	{
		*res_char = (*res_char) << 1;
		*res_char += 0;
		(*bit)++;
	}
	else
	{
		(*res_char) = (*res_char) << 1;
		*res_char += 1;
		(*bit)++;
	}
	return (*res_char);
}

void	myaction(int signum, siginfo_t *siginfo, void *code)
{
	static int	bit;
	static int	res_char;

	(void)code;
	res_char = add_bit(signum , &bit, &res_char);
	if (bit == 8)
	{
		if (res_char != 0)
			ft_putchar(res_char);
		else if (kill(siginfo->si_pid, SIGUSR1))
			ft_putstr_fd("Error exit\n", 1);
		res_char = 0;
		bit = 0;
	}
}

void	set_values(struct sigaction *act, sigset_t non_mask)
{
	act->sa_handler = 0;
	act->sa_flags = SA_SIGINFO;
	act->sa_mask = non_mask;
	act->sa_sigaction = myaction;
}

int	main(void)
{
	struct sigaction	act;
	sigset_t			non_mask;

	if (sigemptyset(&non_mask) == -1 || \
		sigaddset(&non_mask, SIGINT) == -1)
		printf("\n| error sigaddset() |\n");
	set_values(&act, non_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1 || \
		sigaction(SIGUSR2, &act, NULL) == -1)
		printf("\n| error sigaction() |\n");
	ft_putnbr_fd(getpid(), 1);
	printf("%d\n", getpid());
	while (1)
	{
		pause();
	}
}