/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:00:22 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/17 12:39:25 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memset.c"
#include <stdio.h>
#include <string.h>

int main()
{
	char string[] = "this is a string";
	char find = '$';

	printf("%s", string);
	ft_memset(string, find, 6);
	//memset(string, '!', 6);
	printf("\n%s", string);
}
