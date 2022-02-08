/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:15:57 by jthiele           #+#    #+#             */
/*   Updated: 2022/02/08 15:24:44 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char delim)
{
	size_t	words;
	size_t	i;
	char	flag;

	words = 0;
	i = 0;
	flag = 1;
	while (s[i])
	{
		if (flag && s[i] != delim)
		{
			flag = 0;
			words++;
		}
		else if (!flag && s[i] == delim)
			flag = 1;
		i++;
	}
	return (words);
}

static char	*populatestr(char const **s, char c)
{
	char	*str;
	size_t	len;

	len = 0;
	while (**s && **s == c)
		(*s)++;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (str);
	ft_memcpy(str, *s, len);
	*s += len;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	i;
	char	**strs;

	i = 0;
	if (!s)
		return (NULL);
	words = word_count(s, c);
	strs = ft_calloc(words + 1, sizeof(char *));
	if (!strs)
		return (strs);
	while (i < words)
	{
		strs[i] = populatestr(&s, c);
		if (!strs[i])
			return (0);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
