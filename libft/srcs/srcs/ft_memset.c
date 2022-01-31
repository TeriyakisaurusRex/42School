/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:52:09 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/28 16:18:50 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (n-- && str[i])
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
