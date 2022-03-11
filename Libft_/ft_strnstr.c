/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:18:29 by hsybassi          #+#    #+#             */
/*   Updated: 2021/10/22 17:18:29 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_big;
	size_t	len_little;
	size_t	i;
	size_t	tmp_len;

	if (!big && !little)
		return (NULL);
	if (*little == 0)
		return ((char *)big);
	len_big = ft_strlen(big);
	len_little = ft_strlen(little);
	tmp_len = len;
	i = 0;
	if (len_big >= len_little)
	{
		while ((i <= len_big - len_little) && (tmp_len--) && \
		(i + len_little <= len))
		{
			if (ft_strncmp(&(big[i]), little, ft_strlen(little)) == 0)
				return ((char *)&(big[i]));
			i++;
		}
	}
	return (NULL);
}
