/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:15:57 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/24 14:34:35 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strddup(char *s1, char d)
{
	int		size;
	char	*ptr;
	int		i;

	size = ft_strdlen(s1, d);
	ptr = malloc((size + 1) * sizeof(char));
	i = 0;
	if (!ptr)
		return (0);
	while (s1[i] && s1[i] != d)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*above code dupplicates and array up to the delimeter or null terminating character*/

char	**ft_split(char const *s, char c)
{
	char **rtnar; //return array
	char *ts; //total string
	char *delimeter;
	int delimetercount;
	int nbrstrs; //number of strings

	int i;

	i = 0;
	delimetercount = 0;
	delimeter = malloc(2); //free this later
	delimeter[0] = c;	//making a very small array
	delimeter[1] = '\0';	//because ft_strtrim wants a list of delimeters
	ts = ft_strtrim(s, delimeter); //make a new big string with ends chopped off
	while (ts[i]) //count delimeters
	{
		if (ts[i] == c && ts[i + 1] != c)
			delimetercount++;
		i++;
	}
	i = 0; //reuse i
	nbrstrs = delimetercount + 1; //number of string is always 1 more than delim
	rtnar = malloc(sizeof(rtnar) * (nbrstrs + 1)); //malloc amount of strings
	int lis = 0; //location in string

	/*Testing*/
	ft_putchar_fd(lis + '0', 1);
	/*comment out the above line to seg fault*/

	while (nbrstrs) //we are gonna make this many strings
	{

		rtnar[i] = ft_strddup(ts + lis, c); //new string is dupped from ar pointer
		lis += ft_strlen(rtnar[i]); //move the pointer along
		while (ts[lis] == c) //move the pointer across delimiters if there's multi
			lis++;
		nbrstrs--;
		i++;
	}

	free(delimeter);
	rtnar[i] = NULL; // Null terminate the last element in the string array

	return (rtnar);
}
