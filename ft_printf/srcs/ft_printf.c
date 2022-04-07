/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:29:56 by jthiele           #+#    #+#             */
/*   Updated: 2022/03/21 14:52:27 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_print_format(const char format, va_list args)
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, char)));
	else if (format == 's')
		return (ft_print_string(args, char));
	else if (format == 'p')
		return ();
	else if (format == 'i' || format = 'd')
		return ();
	else if (format == 'u')
		return ();
	else if (format == 'x')
		return ();
	else if (format == 'X')
		return ();
	else if (format == '%')
		return ();
	/*
	else if (format == 'b')
		return (base ["01"]);
	else if (format == '!')
		return (ft_strlen(putstr("\u001b[31m"))
	*/
	else
		return ();
}

int ft_printf(const char *str, ...)
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
			count += ft_char_type(str[i], args);
			i++;
		}
		if (str[i] && str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			i++;
			count++;
		}
	}
	va_end(v);
	return (count);
}
