/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:29:56 by jthiele           #+#    #+#             */
/*   Updated: 2022/04/14 15:38:45 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[++i])
		{
			count += ft_print_type(str[i], args);
			i++;
		}
		if (str[i] && str[i] != '%')
		{
			ft_print_char(str[i]);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
