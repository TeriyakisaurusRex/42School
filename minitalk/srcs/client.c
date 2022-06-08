/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:10:11 by jthiele           #+#    #+#             */
/*   Updated: 2022/06/08 14:58:01 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	confirm_send(int bit)
{
	if (bit == SIGUSR2)
	{
		ft_printf("%&Messge Sent Succesfully!\n");
		exit(0);
	}
	if (bit == SIGUSR1)
	{
		ft_printf("%!Error Messge Lost!\n");
		exit(1);
	}
}

void	message_pid(int pid, char *message)
{
	int	i;
	int	client_pid;

	i = 0;
	client_pid = getpid();
	deconstruct(client_pid, pid, 32);
	while (message[i])
	{
		deconstruct((unsigned char)message[i], pid, 8);
		i++;
	}
	deconstruct(0, pid, 8);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("%!ERROR\n");
		ft_printf("Try: %&./client <PID> <MESSAGE>\n");
		return (1);
	}
	signal(SIGUSR1, &confirm_send);
	signal(SIGUSR2, &confirm_send);
	message_pid(ft_atoi(argv[1]), argv[2]);
	sleep(3);
	ft_printf("%!ERROR");
	return (1);
}
