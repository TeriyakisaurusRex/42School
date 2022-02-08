/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:24:00 by jthiele           #+#    #+#             */
/*   Updated: 2022/02/03 13:34:21 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	chars_left;
	size_t	i;

	if (start > ft_strlen(s))
		chars_left = 0;
	else
		chars_left = ft_strlen(s + start);
	if (chars_left < len)
		len = chars_left;
	substr = ft_calloc((len + 1), sizeof(char));
	i = 0;
	if (!substr)
		return (0);
	while (i < len && s[i + start])
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}
