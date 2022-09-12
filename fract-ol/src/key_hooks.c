#include "fractol.h"

static void move_arrow_leftright(int keycode, t_imagewin *imagewin)
{
    t_complex *max;
    t_complex *min;
    double offset;

    max = &imagewin->comp_info.max;
    min = &imagewin->comp_info.min;
    offset = max->r - min->r;
    if(keycode == 65363)
    {
        min->r += offset * 0.01;
        max->r += offset * 0.01;
    }
    if (keycode == 65361)
    {
        min->r -= offset * 0.01;
        max->r -= offset * 0.01;
    }    
}

static void move_arrow_updown(int keycode, t_imagewin *imagewin)
{
    t_complex *max;
    t_complex *min;
    double offset;

    max = &imagewin->comp_info.max;
    min = &imagewin->comp_info.min;
    offset = max->i - min->i;
    if(keycode == 65362)
    {
        min->i += offset * 0.01;
        max->i += offset * 0.01;
    }
    if (keycode == 65364)
    {
        min->i -= offset * 0.01;
        max->i -= offset * 0.01;
    }   
}

int key_press_hook(int keycode, t_imagewin *imagewin)
{
    if (keycode == 65307)
        exit(0);
    if (keycode == 65363 || keycode == 65361)
        move_arrow_updown(keycode, imagewin);
    if (keycode == 65362 || keycode == 65364)
        move_arrow_leftright(keycode, imagewin);
    return(0);
}