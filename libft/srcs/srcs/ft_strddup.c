/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strddup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:24:01 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/31 12:39:27 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strddup(char *s1, char d)
{
	size_t	size;
	char	*ptr;
	int		i;

	size = ft_strdlen(s1, d);
	ptr = ft_calloc((size + 1), sizeof(char));
	i = 0;
	if (!ptr)
		return (ptr);
	while (s1[i] && s1[i] != d)
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}	
