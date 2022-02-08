/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:09:36 by jthiele           #+#    #+#             */
/*   Updated: 2022/02/02 12:33:56 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	c = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (str[i] == c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
