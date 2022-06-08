/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:17:13 by jthiele           #+#    #+#             */
/*   Updated: 2022/06/08 14:09:07 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

void	build_byte(int bit)
{
	int			byte;
	static int	count;
	static int	client_pid;

	byte = reconstruct(bit);
	if (byte >= 0 && count < 4)
	{
		client_pid += byte << count * 8;
		count++;
		if (count == 4)
			ft_printf("Client PID: %i\n", client_pid);
	}
	else if (byte > 0)
		ft_printf("%c", byte);
	else if (!byte)
	{
		ft_printf("\n");
		usleep(1000);
		deconstruct(0, client_pid, 8);
		count = 0;
		client_pid = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, &build_byte);
	signal(SIGUSR2, &build_byte);
	while (1)
		pause();
}
