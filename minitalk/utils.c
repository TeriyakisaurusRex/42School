/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:25:03 by jthiele           #+#    #+#             */
/*   Updated: 2022/06/08 14:18:31 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

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
		byte = 0; //reset
		count = 0;
		return (ret);
	}
	return (-1); //not ready
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
			kill(pid,SIGUSR2);
		byte /= 2;
		usleep(100);
		count++;
	}	
}
