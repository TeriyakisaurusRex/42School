#include "fractol.h"

uint32_t convert_rgb_hex(int r, int g, int b)
{
    uint32_t colour;

    colour = 0;
    colour |= b;
    colour |= g << 8;
    colour |= r << 16;
    return(colour);
}

uint32_t simple_colourizer(int iter, t_imagewin *imagewin)
{
    int a;

    a = (int)((double)iter / imagewin->max_iter * 255);
    return (convert_rgb_hex(a, a, a));
}