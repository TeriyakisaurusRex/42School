/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:19:25 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/21 13:26:09 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_ptr;
	char	*src_ptr;

	dst_ptr = dst;
	src_ptr = (char *)src;
	if (dst_ptr == src_ptr)
		return (dst);
	if (src_ptr - dst_ptr > 0)
	{
		i = 0 - 1;
		while (++i < len)
			dst_ptr[i] = src_ptr[i];
	}
	else
	{
		while (len--)
			dst_ptr[len] = src_ptr[len];
	}
	return (dst);
}
