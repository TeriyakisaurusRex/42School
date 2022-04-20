/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:42:12 by jthiele           #+#    #+#             */
/*   Updated: 2022/04/20 13:39:50 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_type(const char c, va_list v)
{
	if (c == 'c')
		return (ft_print_char(va_arg(v, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(v, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(v, unsigned long)));
	else if (c == 'i' || c == 'd')
		return (ft_print_radix(va_arg(v, int), "0123456789"));
	else if (c == 'u')
		return (ft_print_radix(va_arg(v, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_print_radix(va_arg(v, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_print_radix(va_arg(v, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_print_char('%'));
	else if (c == '!')
		return (ft_print_str("\e[31m"));
	else if (c == '@')
		return (ft_print_str("\e[34m"));
	else if (c == '&')
		return (ft_print_str("\e[32m"));	
	else
		return (0);
}
