/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_radix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:28:52 by jthiele           #+#    #+#             */
/*   Updated: 2022/04/07 12:49:20 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_radix(long long int nb, char *base)
{
	int	length;
	int	n_printed;

	length = 0;
	n_printed = 0;
	while (base[length])
		length++;
	if (nb >= length)
	{
		ft_print_radix((nb / length), length, base);
		ft_print_radix((nb % length), length, base);
	}
	else
		n_printed += ft_print_char(base[nb]);
	return (n_printed)
}
