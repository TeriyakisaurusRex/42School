#include "fractol.h"

void	pixel_draw(t_image *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->ptr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

double abs_double(double val)
{
    if (val < 0)
        return (-val);
    return (val);
}

double squared (double val)
{
    return(val * val);
}

static uint32_t get_fractal_colour(t_imagewin *imagewin)
{
    int     iteration;
    double  tmp_x;
    t_complex_info c_info;

    iteration = 0;
    c_info = imagewin->comp_info;
    while (squared(c_info.z.r) + squared(c_info.z.i) <= 4)
    {
        tmp_x = squared(c_info.z.r) - squared(c_info.z.i) + c_info.c.r;
        if (imagewin->fractal_type != '2')
            c_info.z.i = 2 * c_info.z.r * c_info.z.i + c_info.c.i;
        else
        {
            c_info.z.i = abs_double((double)2 * c_info.z.r * c_info.c.i) + c_info.c.i;
        }
        c_info.z.r = tmp_x;
        iteration++;
        if (iteration == imagewin->max_iter)
            return (convert_rgb_hex(0, 0, 0));
    }
    return (simple_colourizer(iteration, imagewin));
}

void mandelbrot(t_imagewin *imagewin)
{
    int x;
    int y;
    t_complex_info *c_info;

    c_info = &imagewin->comp_info;
    c_info->delta.r = (c_info->max.r - c_info->min.r) / 500; //width
    c_info->delta.i = (c_info->max.i - c_info->min.i) / 500; //height
    y = 0;
    while (y < 500) // height
    {
        x = 0;
        while(x < 500) // width
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

void julia(t_imagewin *imagewin)
{
    int x;
    int y;
    t_complex_info *c_info;

    c_info = &imagewin->comp_info;
    c_info->delta.r = (c_info->max.r - c_info->min.r) / 500; //width
    c_info->delta.i = (c_info->max.i - c_info->min.i) / 500; //height
    y = 0;
    while (y < 500) // height
    {
        x = 0;
        while(x < 500) // width
        {
            c_info->z.i = c_info->min.i + y * c_info->delta.i;
            c_info->z.r = c_info->min.r + x * c_info->delta.r;
            pixel_draw(&imagewin->image, x, y, get_fractal_colour(imagewin));
            x++;
        }
        y++;
    }
}