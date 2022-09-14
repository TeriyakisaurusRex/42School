/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:46:50 by jthiele           #+#    #+#             */
/*   Updated: 2022/09/13 14:52:11 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	magnify(double start, double end, double magnification)
{
	double	offset;

	offset = end - start;
	return (start + (offset * magnification));
}

static void	zoom_imagewin(t_imagewin *imagewin, int keycode, int x, int y)
{
	double			mouse_r;
	double			mouse_i;
	double			magnification;
	t_complex_info	*c_info;

	c_info = &imagewin->comp_info;
	mouse_r = (double) x / (WIN_WIDTH / (c_info->max.r - c_info->min.r))
		+ c_info->min.r;
	mouse_i = (double) y / (WIN_HEIGHT / (c_info->max.i - c_info->min.i))
		+ c_info->min.i;
	if (keycode == 5)
	{
		if (imagewin->max_iter > 4)
			imagewin->max_iter -= 4;
		magnification = 1.0 / 0.8;
	}
	if (keycode == 4)
	{
		imagewin->max_iter += 4;
		magnification = 1.0 / 1.2;
	}
	c_info->min.r = magnify(mouse_r, c_info->min.r, magnification);
	c_info->min.i = magnify(mouse_i, c_info->min.i, magnification);
	c_info->max.r = magnify(mouse_r, c_info->max.r, magnification);
	c_info->max.i = magnify(mouse_i, c_info->max.i, magnification);
}

int	mouse_press_hook(int keycode, int x, int y, t_imagewin *imagewin)
{
	if (keycode == 5 || keycode == 4)
		zoom_imagewin(imagewin, keycode, x, y);
	return (0);
}
