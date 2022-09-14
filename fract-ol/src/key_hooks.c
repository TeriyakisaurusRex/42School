/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:37:06 by jthiele           #+#    #+#             */
/*   Updated: 2022/09/13 14:41:02 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	end(t_imagewin *imagewin)
{
	mlx_destroy_window(imagewin->mlx, imagewin->win);
	exit(0);
}

static void	move_leftright(int keycode, t_imagewin *imagewin)
{
	t_complex	*max;
	t_complex	*min;
	double		offset;

	max = &imagewin->comp_info.max;
	min = &imagewin->comp_info.min;
	offset = max->r - min->r;
	if (keycode == KEY_RIGHT)
	{
		min->r += offset * 0.01;
		max->r += offset * 0.01;
	}
	if (keycode == KEY_LEFT)
	{
		min->r -= offset * 0.01;
		max->r -= offset * 0.01;
	}
}

static void	move_updown(int keycode, t_imagewin *imagewin)
{
	t_complex	*max;
	t_complex	*min;
	double		offset;

	max = &imagewin->comp_info.max;
	min = &imagewin->comp_info.min;
	offset = max->i - min->i;
	if (keycode == KEY_UP)
	{
		min->i += offset * 0.01;
		max->i += offset * 0.01;
	}
	if (keycode == KEY_DOWN)
	{
		min->i -= offset * 0.01;
		max->i -= offset * 0.01;
	}
}

int	key_press_hook(int keycode, t_imagewin *imagewin)
{
	if (keycode == KEY_ESC)
		end(imagewin);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		move_updown(keycode, imagewin);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		move_leftright(keycode, imagewin);
	return (0);
}
