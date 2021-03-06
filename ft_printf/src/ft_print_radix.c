/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_radix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:28:52 by jthiele           #+#    #+#             */
/*   Updated: 2022/04/14 15:40:41 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_num_length(long long int nb, char *base)
{
	int	count;
	int	radix;

	count = 0;
	radix = 0;
	while (base[radix])
		radix++;
	if (!nb)
		return (1);
	while (nb > 0)
	{
		nb /= radix;
		count++;
	}
	return (count);
}

int	ft_print_radix(long long int nb, char *base)
{
	int	length;
	int	n_printed;

	length = 0;
	n_printed = 0;
	if (nb < 0)
	{
		nb *= -1;
		ft_print_char('-');
		n_printed = 1;
	}
	n_printed += ft_num_length(nb, base);
	while (base[length])
		length++;
	if (nb >= length)
	{
		ft_print_radix((nb / length), base);
		ft_print_radix((nb % length), base);
	}
	else
	{
		ft_print_char(base[nb]);
	}
	return (n_printed);
}
