/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:33:14 by jthiele           #+#    #+#             */
/*   Updated: 2022/06/30 13:39:08 by jthiele          ###   ########.fr       */
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

void update_fractal_c(t_imagewin *imagewin)
{
    int x;
    int y;
    double mouse_r;
    double mouse_i;
    t_complex_info *c_info;

    c_info = &imagewin->comp_info;
    mlx_mouse_get_pos(imagewin->mlx, &x, &y);
    mouse_r = (double)x / ( 500 / (c_info->max.r - c_info->min.r)) + c_info->min.r;
    mouse_i = (double)y / ( 500 / (c_info->max.i - c_info->min.i)) * -1 + c_info->min.i;
    c_info->c.r = mouse_r;
    c_info->c.i = mouse_i;    
}

int main_loop(t_imagewin *imagewin)
{
    if (imagewin->is_pressed_mouse_left)
        update_fractal_c(imagewin);
    if (imagewin->fractal_type == '0' || imagewin->fractal_type == '2')
        mandelbrot(imagewin);
    else if (imagewin->fractal_type == '1')
        julia(imagewin);
    mlx_put_image_to_window(imagewin->mlx, imagewin->win, imagewin->image.image, 0, 0);
    return(0);
}

int main(int argc, char **argv)
{
    t_imagewin imagewin;

    if (argc != 2 || (!(argv[1][0] == '0' || argv[1][0] == '1' || argv[1][0] == '2' || argv[1][1] == '\0')))
    {
        //write to console "FAIL"
        return(1);
    }
    imagewin.fractal_type = argv[1][0];
    init_imagewin(&imagewin);
    mlx_hook(imagewin.win, 2, 1L << 17, end, &imagewin);
    mlx_hook(imagewin.win, 2, 1L << 0, key_press_hook, &imagewin);
    mlx_mouse_hook(imagewin.win, mouse_press_hook, &imagewin);
    mlx_hook(imagewin.win, 3, 1L << 3, mouse_release_hook, &imagewin);
    mlx_loop_hook(imagewin.mlx, &main_loop, &imagewin);
    mlx_loop(imagewin.mlx);
    return(0);
}
