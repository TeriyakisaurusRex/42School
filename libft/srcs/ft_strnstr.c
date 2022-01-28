/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:40:27 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/19 16:15:25 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(needle[i]))
		return ((char *)haystack);
	while (len-- && haystack[i])
	{	
		if (haystack[i] == needle[j])
		{
			j++;
			if (!(needle[j]))
				return ((char *)haystack + i - j + 1);
		}
		else if (j != 0)
			j = 0;
		i++;
	}
	return (0);
}
