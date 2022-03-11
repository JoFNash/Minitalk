/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:16:26 by hsybassi          #+#    #+#             */
/*   Updated: 2021/10/22 18:07:00 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	i;

	mem = (void *)malloc(size * count);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)mem)[i] = '\0';
		i++;
	}
	return (mem);
}
