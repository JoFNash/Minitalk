/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:37:32 by hsybassi          #+#    #+#             */
/*   Updated: 2022/03/17 16:55:22 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	get(int myint)
{
	(void)myint;
	ft_putstr_fd("Message was got\n", 1);
	exit(0);
}

void	send_char(char c, int ppid)
{
	int	i;

	i = 128;
	while (i != 0)
	{
		if (i & c)
		{
			if (kill(ppid, SIGUSR1))
			{
				ft_putstr_fd("Error: SIGUSR1\n", 1);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(ppid, SIGUSR2))
			{
				ft_putstr_fd("Error: SIGUSR2\n", 1);
				exit(EXIT_FAILURE);
			}
		}
		i /= 2;
		usleep(500);
	}
}

void	send(pid_t ppid, char *message)
{
	while (*message)
	{
		send_char(*message, ppid);
		message++;
	}
	send_char(ppid, 0);
}

int	main(int argc, char *argv[])
{
	pid_t	ppid;
	char	*message;

	signal(SIGUSR1, get);
	if (argc != 3)
	{
		printf("Enter please: ./client <pid> <message>");
		exit(EXIT_FAILURE);
	}
	ppid = (pid_t)ft_atoi(argv[1]);
	message = argv[2];
	send(ppid, message);
	while (1)
		pause();
	return (0);
}
