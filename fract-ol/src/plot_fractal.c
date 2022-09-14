/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:52:21 by jthiele           #+#    #+#             */
/*   Updated: 2022/09/14 13:22:00 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	get_fractal_colour(t_imagewin *imagewin)
{
	int				iteration;
	double			tmp_x;
	t_complex_info	c_info;

	iteration = 0;
	c_info = imagewin->comp_info;
	while (squared(c_info.z.r) + squared(c_info.z.i) <= 4)
	{
		tmp_x = squared(c_info.z.r) - squared(c_info.z.i) + c_info.c.r;
		if (imagewin->fractal_type != '3')
			c_info.z.i = 2 * c_info.z.r * c_info.z.i + c_info.c.i;
		else
		{
			c_info.z.i = abs_double((double)
					2 * c_info.z.r * c_info.c.i) + c_info.c.i;
		}
		c_info.z.r = tmp_x;
		iteration++;
		if (iteration == imagewin->max_iter)
			return (convert_rgb_hex(0, 0, 0));
	}
	return (simple_colourizer(iteration, imagewin));
}

void	mandelbrot(t_imagewin *imagewin)
{
	int				x;
	int				y;
	t_complex_info	*c_info;

	c_info = &imagewin->comp_info;
	c_info->delta.r = (c_info->max.r - c_info->min.r) / WIN_WIDTH;
	c_info->delta.i = (c_info->max.i - c_info->min.i) / WIN_HEIGHT;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			c_info->z.r = 0;
			c_info->z.i = 0;
			c_info->c.i = c_info->min.i + y * c_info->delta.i;
			c_info->c.r = c_info->min.r + x * c_info->delta.r;
			pixel_draw(&imagewin->image, x, y, get_fractal_colour(imagewin));
			x++;
		}
		y++;
	}
}

void	julia(t_imagewin *imagewin)
{
	int				x;
	int				y;
	t_complex_info	*c_info;

	c_info = &imagewin->comp_info;
	c_info->delta.r = (c_info->max.r - c_info->min.r) / WIN_WIDTH;
	c_info->delta.i = (c_info->max.i - c_info->min.i) / WIN_HEIGHT;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			c_info->z.i = c_info->min.i + y * c_info->delta.i;
			c_info->z.r = c_info->min.r + x * c_info->delta.r;
			pixel_draw(&imagewin->image, x, y, get_fractal_colour(imagewin));
			x++;
		}
		y++;
	}
}

void	julia2(t_imagewin *imagewin)
{
	int				x;
	int				y;
	t_complex_info	*c_info;

	c_info = &imagewin->comp_info;
	c_info->delta.r = (c_info->max.r - c_info->min.r) / WIN_WIDTH;
	c_info->delta.i = (c_info->max.i - c_info->min.i) / WIN_HEIGHT;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			c_info->c.r = -0.79;
			c_info->c.i = 0.15;
			c_info->z.i = c_info->min.i + y * c_info->delta.i;
			c_info->z.r = c_info->min.r + x * c_info->delta.r;
			pixel_draw(&imagewin->image, x, y, get_fractal_colour(imagewin));
			x++;
		}
		y++;
	}
}
