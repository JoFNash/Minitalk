/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:18:34 by hsybassi          #+#    #+#             */
/*   Updated: 2021/10/27 17:57:47 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char_in_s(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	count_begin_char(const char *s1, const char *set)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (check_char_in_s(s1[0], set) == 1)
	{
		while (check_char_in_s(s1[i], set) == 1)
		{
			count++;
			i++;
		}
		return (count);
	}
	return (0);
}

static size_t	count_end_char(const char *s1, const char *set)
{
	size_t	count;
	size_t	len_s1;
	size_t	i;

	count = 0;
	len_s1 = ft_strlen(s1);
	i = len_s1 - 1;
	if (check_char_in_s(s1[i], set) == 1)
	{
		if (i == 0 && check_char_in_s(s1[i], set) == 1)
			return (count + 1);
		while (check_char_in_s(s1[i], set) == 1 && i != 0)
		{
			count++;
			i--;
		}
		return (count);
	}
	return (0);
}

static size_t	count_len(size_t begin, size_t end, size_t len, const char *s1)
{
	if (begin + end > len)
		len = 0;
	else
		len = ft_strlen(s1) - (begin + end);
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	begin;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	begin = count_begin_char(s1, set);
	end = count_end_char(s1, set);
	len = ft_strlen(s1);
	len = count_len(begin, end, len, s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (len--)
	{
		str[i] = s1[i + begin];
		i++;
	}
	str[i] = '\0';
	return (str);
}
