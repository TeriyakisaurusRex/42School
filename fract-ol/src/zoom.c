/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:28:02 by jthiele           #+#    #+#             */
/*   Updated: 2022/06/29 13:32:42 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	mouse_complex(t_mouse *mouse)
{
	mouse->mouse_complex.r = (((double)mouse->x / ((1920) * 0.26) - 2)); //adjust this, this is lerp
	mouse->mouse_complex.i = (((double)mouse->y / ((1080) * 0.45) - 1.1)); //adjust this, this is lerp
}

int	mouse_hook_init(int keycode, int x, int y, t_mouse *mouse)
{
	mouse->isdown = keycode;
	if (mouse->isdown == 4)
	{
		mouse->x = x;
		mouse->y = y;
		mouse->zoomval += 1;
	}
	if (mouse->isdown == 5)
	{
		mouse->x = x;
		mouse->y = y;
		mouse->zoomval -=1;
	}
	mouse_complex(mouse);
	return (0);
}
