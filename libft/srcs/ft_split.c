/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:15:57 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/31 13:33:34 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strtrimdelimeter(char const *s, char c)
{
	char	*delimeter;
	char	*rtn;

	delimeter = ft_calloc(2, sizeof(char));
	delimeter[0] = c;
	rtn = ft_strtrim(s, delimeter);
	free(delimeter);
	return (rtn);
}

static int	populatearray(int nbrstrs, char **rtnar, char c, char *ts)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nbrstrs--)
	{
		rtnar[i] = ft_strddup(ts + j, c);
		j += ft_strlen(rtnar[i]);
		while (ts[j] == c)
			j++;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**rtnar;
	char	*ts;
	int		delimetercount;
	int		nbrstrs;
	int		i;

	ts = strtrimdelimeter(s, c);
	i = 0;
	delimetercount = 0;
	while (ts[i])
	{
		if (ts[i] == c && ts[i + 1] != c)
			delimetercount++;
		i++;
	}
	i = 0;
	nbrstrs = delimetercount + 1;
	rtnar = ft_calloc(sizeof(rtnar), (nbrstrs + 1));
	populatearray(nbrstrs, rtnar, c, ts);
	return (rtnar);
}
