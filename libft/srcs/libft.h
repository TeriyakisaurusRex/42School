/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:07:09 by jthiele           #+#    #+#             */
/*   Updated: 2022/01/17 13:33:42 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>


int ft_isupper(char c);
int ft_islower(char c);
int ft_isalpha(char c);
int ft_isdigit(char c);
int ft_isascii(char c);
int ft_isalnum(char c);
int ft_isprint(char c);

int ft_strlen(char *string);

int strncmp(const char *s1, const char *s2, size_t n);

unsigned char ft_isupper(unsigned char c);
unsigned char ft_islower(unsigned char c);

char *ft_strchr(const char *s, char c);
char *ft_strrchr(const char *s, char c);

void *ft_memset(void *str, int c, size_t n);
void ft_bzero(void *s, size_t n);

#endif
