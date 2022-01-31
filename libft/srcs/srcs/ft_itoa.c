/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:12:49 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/28 14:50:58 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdigits(long int n)
{
	unsigned int	rtn;

	rtn = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		rtn++;
		n *= -1;
	}
	while (n)
	{
		rtn++;
		n /= 10;
	}
	return (rtn);
}

char	*ft_itoa(int n)
{
	long int		nb;
	int				sign;	
	char			*rtn;
	unsigned int	numdigit;

	nb = n;
	sign = 0;
	numdigit = countdigits(nb);
	if (nb < 0)
	{
		nb *= -1;
		sign = -1;
	}
	rtn = malloc(sizeof(*rtn) * numdigit);
	if (!rtn)
		return (0);
	rtn[0] = '-';
	while (numdigit + sign)
	{
		rtn[numdigit - 1] = (nb % 10 + '0');
		nb /= 10;
		numdigit--;
	}
	return (rtn);
}
