/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:20:20 by jthiele           #+#    #+#             */
/*   Updated: 2022/04/07 13:24:26 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../included/ft_printf.h"

int	ft_print_ptr(unsigned long ptr)
{
	int	n_printed;

	n_printed = ft_print_str("0x");
	n_printed += ft_print_radix(ptr, "0123456789ABCDEF");
	return (n_printed);
}
