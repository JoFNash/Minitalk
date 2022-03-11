/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsybassi <hsybassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:17:54 by hsybassi          #+#    #+#             */
/*   Updated: 2021/10/27 17:58:05 by hsybassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_words(char const *s, char c)
{
	size_t	i;
	int		words;

	words = 0;
	i = 0;
	if (s[0] != c)
		++words;
	if (ft_strlen(s) != 0)
	{
		while (i < ft_strlen(s) - 1 && s[i + 1] != '\0')
		{
			if (s[i] == c && s[i + 1] != c)
			{
				++words;
			}
			i++;
		}
	}
	return (words);
}

static void	alloc_mem(char **mass, int length, size_t *k)
{
	mass[*k] = (char *)malloc(sizeof(char) * (length + 1));
	if (!mass[*k])
	{
		while ((*k)--)
		{
			free(mass[*k]);
		}
		free(mass);
	}
	(*k)++;
}

static void	get_mem_for_words(char const *s, char c, char **mass)
{
	int		length;
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	while (s[i] != '\0')
	{
		length = 0;
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			if (s[i] == '\0')
				break ;
			while (s[i] != c && s[i] != '\0')
			{
				length++;
				i++;
			}
		}
		if (length != 0)
			alloc_mem(mass, length, &k);
	}
}

static char	**get_mass(char const *s, char c, char **mass)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			if (s[i] == '\0')
				break ;
			k = 0;
			while (s[i] != c && s[i] != '\0')
			{
				mass[j][k++] = s[i++];
			}
			mass[j++][k] = '\0';
		}
	}
	if (s[i] == '\0')
		mass[j] = NULL;
	return (mass);
}

char	**ft_split(char const *s, char c)
{
	char	**mass;
	int		words;

	if (!s)
		return (NULL);
	words = get_num_words(s, c);
	mass = (char **)malloc(sizeof(char *) * (words + 1));
	if (!mass)
		return (NULL);
	get_mem_for_words(s, c, mass);
	mass = get_mass(s, c, mass);
	return (mass);
}
