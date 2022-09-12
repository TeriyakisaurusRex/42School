#include "fractol.h"

static double magnify(double start, double end, double magnification)
{
    double offset;

    offset = end - start;
    return (start + (offset * magnification));
}

static void zoom_imagewin(t_imagewin *imagewin, int keycode, int x, int y)
{
    double mouse_r;
    double mouse_i;
    double magnification = 0.2;
    t_complex_info *c_info;

    c_info = &imagewin->comp_info;
    mouse_r = (double)x / ( 500 / (c_info->max.r - c_info->min.r)) + c_info->min.r;
    mouse_i = (double)y / ( 500 / (c_info->max.i - c_info->min.i)) + c_info->min.i;
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

int mouse_press_hook(int keycode, int x, int y, t_imagewin *imagewin)
{
    if (keycode == 5 || keycode == 4)
        zoom_imagewin(imagewin, keycode, x, y);
    else if (keycode == 1)
        imagewin->is_pressed_mouse_left = true;
    return(0);
}

int mouse_release_hook(int keycode, int x, int y, t_imagewin *imagewin)
{
    (void)x;
    (void)y;
    if (keycode == 1)
        imagewin->is_pressed_mouse_left = false;
    return(0);
}