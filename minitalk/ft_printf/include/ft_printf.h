/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:44:55 by jthiele           #+#    #+#             */
/*   Updated: 2022/04/14 13:38:14 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);

int	ft_print_char(int c);
int	ft_print_ptr(unsigned long ptr);
int	ft_print_radix(long long int nb, char *base);
int	ft_print_str(char *str);
int	ft_print_type(const char c, va_list v);

#endif
