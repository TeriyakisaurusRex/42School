/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:09:36 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/17 13:33:37 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memchr(const void *s, int c, size_t n)
{
	unsigned char	d;
	unsigned char	*str;
	int				i;

	d = c;
	str = (unsigned char *)b;
	i = 0;
	
	while (n && str[i])
	{
		if (str[i] == d)
			return ((void *)(s + i))
		i++;
		n--;
	}
	
}
