/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:32:10 by jthiele           #+#    #+#             */
/*   Updated: 2022/09/14 13:55:09 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"

double	abs_double(double val)
{
	if (val < 0)
		return (-val);
	return (val);
}

double	squared(double val)
{
	return (val * val);
}

void	pixel_draw(t_image *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->ptr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

uint32_t	convert_rgb_hex(int r, int g, int b)
{
	uint32_t	colour;

	colour = 0;
	colour |= b;
	colour |= g << 8;
	colour |= r << 16;
	return (colour);
}

uint32_t	simple_colourizer(int iter, t_imagewin *imagewin)
{
	int	a;
	int	b;
	int	c;

	a = (int)((double)iter / imagewin->max_iter * 255);
	b = (int)((double)iter * 1.2 / imagewin->max_iter * 255);
	c = (int)((double)iter * 3 - 152 / imagewin->max_iter * 255);
	return (convert_rgb_hex(a, b, c));
}
