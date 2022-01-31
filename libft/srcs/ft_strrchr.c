/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:19:19 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/19 11:57:38 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	*last;

	res = (char *)s;
	last = 0;
	c = (char)c;
	while (*res)
	{
		if (*res == c)
			last = (res);
		res++;
	}
	return (last);
}
