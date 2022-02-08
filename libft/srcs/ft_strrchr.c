/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:19:19 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/31 14:26:35 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	*last;

	if (s == 0)
		return (0);
	res = (char *)s;
	last = 0;
	c = (char)c;
	while (*res)
	{
		if (*res == c)
			last = (res);
		res++;
	}
	if (*res == c)
		last = res;
	return (last);
}
