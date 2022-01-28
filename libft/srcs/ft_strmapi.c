/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:21:06 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/24 15:37:12 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*rtn;

	len = ft_strlen(s);
	i = 0;
	rtn = malloc(sizeof(rtn) * (len + 1));
	if (!rtn)
		return 0;
	
	while (i < len)
	{
		rtn = f(i, s[i]);
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}