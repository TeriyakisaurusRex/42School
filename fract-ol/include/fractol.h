/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:00:58 by jthiele           #+#    #+#             */
/*   Updated: 2022/07/05 13:42:34 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stdint.h> // ?
# include <pthread.h> // ?
# include <math.h>
# include <stdlib.h>
# include <unistd.h> //?
# include <stdbool.h>

typedef struct s_image
{
	void *image;
	char *ptr;
	int bits_per_pixel;
	int line_length;
	int endian;
    int width; // window
    int height; // window
}	t_image;

typedef struct s_complex
{
	double r;
	double i;
}	t_complex;

typedef struct s_complex_info
{
    t_complex   z;
    t_complex   c;
    t_complex   delta;
    t_complex   max;
    t_complex   min;
}   t_complex_info;

typedef struct s_imagewin
{
	void *mlx;
	void *win;
    int max_iter;
    bool is_pressed_mouse_left;
    char fractal_type; // ?
	t_image image;
    t_complex_info comp_info;
}	t_imagewin;

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

typedef uint32_t (*t_get_colour_func)(t_imagewin *);
void mandelbrot(t_imagewin *imagewin);
void julia(t_imagewin *imagewin);
int mouse_hook_init(int keycode, int x, int y, t_mouse *mouse);
int end(int keycode, t_imagewin *imagewin);
int key_press_hook(int keycode, t_imagewin *imagewin);
int mouse_press_hook(int keycode, int x, int y, t_imagewin *imagewin);
int mouse_release_hook(int keycode, int x, int y, t_imagewin *imagewin);
void init_imagewin(t_imagewin *imagewin);
uint32_t convert_rgb_hex(int r, int g, int b);
uint32_t simple_colourizer(int iter, t_imagewin *imagewin);
double abs_double(double val);
double squared(double num);
void	pixel_draw(t_image *data, int x, int y, int colour);

#endif
