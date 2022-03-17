/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:37:34 by hsybassi          #+#    #+#             */
/*   Updated: 2022/03/17 18:09:06 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	add_bit(int signum, int *bit, int *res_char)
{
	if (signum == SIGUSR1)
	{
		*res_char = (*res_char) << 1;
		*res_char += 1;
		(*bit)++;
	}
	else
	{
		(*res_char) = (*res_char) << 1;
		*res_char += 0;
		(*bit)++;
	}
	return (*res_char);
}

void	myaction(int signum, siginfo_t *siginfo, void *code)
{
	static int	bit = 0;
	static int	res_char = 0;

	(void)code;
	res_char = add_bit(signum, &bit, &res_char);
	if (bit == 8)
	{
		if (res_char != 0)
			ft_putchar_fd(res_char, 1);
		else if (kill(siginfo->si_pid, SIGUSR1))
			ft_putstr_fd("Error exit\n", 1);
		res_char = 0;
		bit = 0;
	}
}

void	print_pid(void)
{
	ft_putstr_fd("My pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	set_values(struct sigaction *act, sigset_t non_mask)
{
	act->sa_flags = SA_SIGINFO;
	act->sa_mask = non_mask;
	act->sa_sigaction = myaction;
}

int	main(void)
{
	struct sigaction	act;
	sigset_t			non_mask;

	if (sigemptyset(&non_mask) == -1)
		ft_putstr_fd("Error: sigaddset()\n", 1);
	set_values(&act, non_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1 || \
		sigaction(SIGUSR2, &act, NULL) == -1)
		ft_putstr_fd("Error: sigaction()\n", 1);
	print_pid();
	while (1)
	{
		pause();
	}
}
