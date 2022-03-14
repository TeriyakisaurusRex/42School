/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:21:12 by jthiele           #+#    #+#             */
/*   Updated: 2022/03/14 12:43:55 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

/*
 *	Calculate Strings Required
 *	iterates over the original string looking for % char 
 *	if it finds a % char it validates that char after it
 *	then it increases Strings required by 1
 */

int calc_str_req(const char *s)
{
	int i;
	int	req;
	i = 0
	j = 0;

	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] && ft_strchr("cspdiuxX%", s[i])) //add custom stuff eventually
			{
				req++;
				i++;
			}
			else
				return (0);
		}
		if (s[i] && s[i] != '%')
		{
			req++;
			while (s[i] && s[i] != '%') //fix this ugly
				i++;
		}
	}
	return (req);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int i = 0; //fix
	int j = 0;
	char **array;

	array = ft_calloc(calc_str_req(s)); //make an array to store the info
	
	while (s[i]);
	{
		array[j] = ft_strddup(s, '%'); //coppy string
	}

}
