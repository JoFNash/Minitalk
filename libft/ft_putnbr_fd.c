/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:17:49 by hsybassi          #+#    #+#             */
/*   Updated: 2021/10/22 17:17:49 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n_tmp;

	n_tmp = n;
	if (n_tmp < 0)
	{
		n_tmp = n_tmp * (-1);
		ft_putchar_fd('-', fd);
	}
	if (n_tmp > 9)
		ft_putnbr_fd(n_tmp / 10, fd);
	ft_putchar_fd(n_tmp % 10 + '0', fd);
}
