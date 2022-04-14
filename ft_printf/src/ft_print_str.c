/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:03:57 by jthiele           #+#    #+#             */
/*   Updated: 2022/04/14 13:36:09 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_str(char *str)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
		return (ft_print_str("(null)"));
	while (str[i])
		ft_print_char(str[i]);
		i++;
	return (i);
}
