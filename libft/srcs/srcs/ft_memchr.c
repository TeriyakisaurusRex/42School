/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:09:36 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/28 14:29:45 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	d;
	unsigned char	*str;
	int				i;

	d = (unsigned char *)c;
	str = (unsigned char *)b;
	i = 0;
	while (n-- && str[i])
	{
		if (str[i] == d)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
