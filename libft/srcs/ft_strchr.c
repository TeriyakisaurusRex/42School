/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:41:47 by jthiele           #+#    #+#             */
/*   Updated: 2022/02/02 11:09:07 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = (char *)s;
	c = (char)c;
	if (s == 0)
		return (0);
	while (*res && *res != c)
	{
		res++;
	}
	if (*res == c)
		return (res);
	return (0);
}
