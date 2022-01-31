/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:23:49 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/31 14:41:30 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strdlen(const char *string, char delimeter)
{
	size_t	i;

	i = 0;
	while (string[i] && string[i] != delimeter)
	{
		i++;
	}
	return (i);
}
