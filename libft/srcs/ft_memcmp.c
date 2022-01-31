/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:57:01 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/31 14:54:20 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_p;
	unsigned char	*s2_p;

	i = 0;
	s1_p = (unsigned char *)s1;
	s2_p = (unsigned char *)s2;
	if (!n)
		return (0);
	while (--n)
	{
		if (s1_p[i] == s2_p[i])
			i++;
		if (s1_p[i] != s2_p[i])
			return (s1_p[i] - s2_p[i]);
	}
	return (s1_p[i] - s2_p[i]);
}
