/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:33:14 by jthiele           #+#    #+#             */
/*   Updated: 2022/06/29 14:12:16 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	end(int keycode, t_imagewin *imagewin)
{
	if (keycode == 53)
	{
		mlx_destroy_window(imagewin->mlx, imagewin->win);
		exit(0);
	}
	return (0);
}

int	render_next_frame(t_hold *hold)
{
	if (hold->mouse->isdown == 4 || hold->mouse->isdown == 5)
	{
		draw_screen(hold->imagewin, hold->mouse, hold->render);
		hold->mouse->isdown = 0;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_mouse	mouse;
	t_imagewin imagewin;
	int	render;
	t_hold	hold;

	render = 0;
	if	(argc == 2 || argv[0][0] != 0)
		render = 1; //change this
	else
		return (0); //error
	imagewin.mlx = mlx_init();
	imagewin.win = mlx_new_window(imagewin.mlx, 1920, 1080, "Fract-ol");
	mlx_mouse_hook(imagewin.win, mouse_hook_init, &mouse);
	mlx_hook(imagewin.win, 2, 1L << 0, end, &imagewin);
	hold.imagewin = &imagewin;
	hold.mouse = &mouse;
	mouse.zoomval = 1;
	mouse.isdown = 4;
	hold.render = render;
	mlx_loop_hook(imagewin.mlx, render_next_frame, &hold);
	mlx_loop(imagewin.mlx);
	return (0);
}
