/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:18:32 by hsybassi          #+#    #+#             */
/*   Updated: 2021/10/22 17:18:32 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	size_t	i;

	tmp = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			tmp = ((char *)(&s[i]));
		i++;
	}
	if (c == '\0')
		return ((char *)(&s[i]));
	return (tmp);
}
