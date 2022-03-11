/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:17:35 by hsybassi          #+#    #+#             */
/*   Updated: 2021/10/22 17:17:35 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*copy_dest;
	const unsigned char		*copy_src;
	unsigned int			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	copy_src = (unsigned char *)src;
	copy_dest = (unsigned char *)dest;
	if (copy_dest > copy_src)
	{
		while (n-- != 0)
			copy_dest[n] = copy_src[n];
	}
	if (copy_src > copy_dest)
	{
		while (i < n)
		{
			copy_dest[i] = copy_src[i];
			i++;
		}
	}
	return (dest);
}
