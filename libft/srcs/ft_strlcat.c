/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:17:35 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/19 15:40:22 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	strlcat(char *dst, const char *src, size_t, dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dstsize)
		return (0);
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && (i + j) > dstsize - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < dstsize)
		dst[i + j] = '\0';
	j = 0;
	while (src[j])
		j++;
	return (i + j);
}
