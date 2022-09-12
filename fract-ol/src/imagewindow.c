

#include "fractol.h"

void init_imagewin(t_imagewin *imagewin)
{
    imagewin->mlx = mlx_init();
    if (imagewin->mlx == NULL)
        exit(0);
    imagewin->win = mlx_new_window(imagewin->mlx, 500, 500, "Title");
    if (imagewin->win == NULL)
        exit(0);
    imagewin->image.image = mlx_new_image(imagewin->mlx, 500, 500);
    if (!imagewin->image.image)
        exit(0);
    imagewin->image.ptr = mlx_get_data_addr(imagewin->image.image, &imagewin->image.bits_per_pixel, &imagewin->image.line_length, &imagewin->image.endian);
    imagewin->comp_info.max.r = 2;
    imagewin->comp_info.max.i = 2;
    imagewin->comp_info.min.r = -2;
    imagewin->comp_info.min.i = -2;
    imagewin->comp_info.c.r = 0.4;
    imagewin->comp_info.c.i = -0.325;
    imagewin->is_pressed_mouse_left = false;
    imagewin->max_iter = 100;
}