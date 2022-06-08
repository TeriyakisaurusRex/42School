/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:25:03 by jthiele           #+#    #+#             */
/*   Updated: 2022/06/08 14:57:42 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	reconstruct(int bit)
{
	static int		byte;
	static int		count;
	unsigned char	ret;

	if (bit == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	byte += bit << count;
	count++;
	if (count == 8)
	{
		ret = byte;
		byte = 0;
		count = 0;
		return (ret);
	}
	return (-1);
}

void	deconstruct(int byte, int pid, int bit_num)
{
	int	count;

	count = 0;
	while (byte || count < bit_num)
	{
		if (byte & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		byte /= 2;
		usleep(100);
		count++;
	}	
}

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (c);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		k *= 10;
		k += str[i] - '0';
		i++;
	}
	if (j % 2)
		return (k * -1);
	return (k);
}
