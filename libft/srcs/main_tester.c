/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:00:22 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/31 12:23:48 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"


int main()
{
	char string[] = "__this is__ a _-___string__";
	char c = '_';
	char **array;
	int i = 0;

	array = ft_split(string, c);

	while (array[i])
	{
		ft_putendl_fd(array[i], 1);
		i++;
	}

}
