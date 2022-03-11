/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:17:23 by hsybassi          #+#    #+#             */
/*   Updated: 2021/10/22 17:17:23 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	tmp_c;

	p = (unsigned char *)s;
	tmp_c = (unsigned char) c;
	while (n--)
	{
		if (*p == tmp_c)
		{
			return (p);
		}
		p++;
	}
	return (NULL);
}
