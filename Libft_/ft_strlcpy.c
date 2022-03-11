/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:18:15 by hsybassi          #+#    #+#             */
/*   Updated: 2021/10/22 17:18:15 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (size != 0)
	{
		if (size - 1 <= len)
		{
			ft_memcpy(dest, src, size - 1);
			dest[size - 1] = '\0';
		}
		else
		{
			ft_memcpy(dest, src, len);
			dest[len] = '\0';
		}
	}
	return (len);
}
