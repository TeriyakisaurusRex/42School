/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:42:09 by jthiele           #+#    #+#             */
/*   Updated: 2022/06/29 14:08:45 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

t_complex	xyto_complex(int x, int y, t_mouse *mouse)
{
	t_complex p;

	p.r = (((double)x / ((1920) * 0.26) - 2)) / mouse->zoomval;
	p.i = (((double)y / ((1080) * 0.45) - 1.1)) / mouse->zoomval;
	return (p);
}

int	mandelbrot(int x, int y, t_mouse *mouse)
{
	t_complex z;
	t_complex c;
	t_complex temp;
	int	max_iteration;
	int i;

	max_iteration = 2000;
	i = 0;
	z.r = 0;
	z. i = 0;
	c = xyto_complex(x, y, mouse);
	while(((z.r * z.r + z.i * z.i) < (4)) && (i < max_iteration))
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = temp.r;
		i++;
	}
	return (i);
}

int	julia(int x, int y, t_mouse *mouse)
{
	t_complex z;
	t_complex c;
	t_complex temp;
	int	max_iteration;
	int i;

	max_iteration = 2000;
	i = 0;
	z = xyto_complex(x, y, mouse);
	c.r = 0.28;
	c.i = 0.008;
	while(((z.r * z.r + z.i * z.i) < (4)) && (i < max_iteration))
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = temp.r;
		i++;
	}
	return (i);
}

int	julia2(int x, int y, t_mouse *mouse)
{
	t_complex z;
	t_complex c;
	t_complex temp;
	int	max_iteration;
	int i;

	max_iteration = 2000;
	i = 0;
	z = xyto_complex(x, y, mouse);
	c.r = 0.79;
	c.i = 0.15;
	while(((z.r * z.r + z.i * z.i) < (4)) && (i < max_iteration))
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = temp.r;
		i++;
	}
	return (i);
}

int	burning(int x, int y, t_mouse *mouse)
{
	t_complex z;
	t_complex c;
	t_complex temp;
	int	max_iteration;
	int i;

	max_iteration = 2000;
	i = 0;
	z = xyto_complex(x, y, mouse);
	c = xyto_complex(x, y, mouse);
	while(((z.r * z.r + z.i * z.i) < (4)) && (i < max_iteration))
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * fabs(z.r * z.i) + c.i;
		z.r = temp.r;
		i++;
	}
	return (i);
}

