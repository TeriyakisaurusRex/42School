/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:00:52 by jthiele           #+#    #+#             */
/*   Updated: 2022/06/08 14:04:44 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../ft_printf/include/ft_printf.h"

int		reconstruct(int bit);
void	deconstruct(int byte, int pid, int bit_num);

#endif
