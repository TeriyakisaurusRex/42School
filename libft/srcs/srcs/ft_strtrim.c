/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:10:33 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/28 15:47:04 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	trim_end(const char *s1, const char *set, int dir)
{
	unsigned int	trim;
	unsigned int	i;
	unsigned int	j;

	trim = 0;
	i = 0;
	if (dir > 0)
		j = 0;
	else
		j = ft_strlen(s1) - 1;
	while (set[i])
	{
		if (s1[j] == set[i])
		{
			trim++;
			j += dir;
			i = 0;
		}
		else
			i++;
	}
	return (trim);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	len;

	i = 0;
	j = trim_end(s1, set, 1);
	k = trim_end(s1, set, -1);
	len = (ft_strlen(s1) - (j + k));
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (0);
	while (len--)
	{
		str[i] = s1[i + j];
		i++;
	}
	str[i] = '\0';
	return (str);
}
