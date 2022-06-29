/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:00:58 by jthiele           #+#    #+#             */
/*   Updated: 2022/06/29 13:12:21 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h> // ?
# include <pthread.h> // ?
# include <math.h>
# include <stdlib.h>
# include <unistd.h> //?

typedef struct s_image
{
	void *image;
	char *ptr;
	int bits_per_pixel;
	int stride; //?
	int endian; //?
}	t_image;

typedef struct s_imagewin
{
	void *mlx;
	void *win;
	t_image image;
}	t_imagewin;

typedef struct s_complex
{
	double r; //r?
	double i; //not x and y?
}	t_complex;

typedef struct s_viewport
{
	double xmin;
	double xmax;
	double ymin;
	double ymax;
	double zoom;
	double offx;
	double offy;
	long max;
	t_complex mouse;
}	t_viewport;

typedef struct s_mouse
{
	char isdown;
	int x;
	int y;
	int lastx;
	int lasty;
	double zoomval;
	t_complex mouse_complex;
}	t_mouse;

typedef struct s_hold
{
	t_mouse *mouse;
	t_imagewin *imagewin;
	int render;
}	t_hold;

void draw_screen(t_imagewin *imagewin, t_mouse *mouse, int render);
int mandelbrot(int x, int y, t_mouse *mouse);
int julia(int x, int y, t_mouse *mouse);
int julia2(int x, int y, t_mouse *mouse);
int burning(int x, int y, t_mouse *mouse);
//int other(int x, int y, t_mouse *mouse);
int mouse_hook_init(int keycode, int x, int y, t_mouse *mouse);

#endif
