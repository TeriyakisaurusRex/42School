# Fract-ol
*Computer Graphics Fractols*

### Summary
*This project is about creating graphically beautiful fractals.*

## MiniLibX


>Document & Information to learn
>>[Fractals]()
>>> [Mandelbrot]()
>>> 
>>> [Julia]()
>>
>>[MiniLibx](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

[MiniLibX repo](https://github.com/42Paris/minilibx-linux)

[Getting Started](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx)

[Plotting Algorithms](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set)

The Gist of it
```
for each pixel (Px, Py) on the screen do
    x0 := scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.00, 0.47))
    y0 := scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1.12, 1.12))
    x := 0.0
    y := 0.0
    iteration := 0
    max_iteration := 1000
    while (x*x + y*y ≤ 2*2 AND iteration < max_iteration) do
        xtemp := x*x - y*y + x0
        y := 2*x*y + y0
        x := xtemp
        iteration := iteration + 1
    
    color := palette[iteration]
    plot(Px, Py, color)
```
Optimised Mandelbrot
```
x2 := 0
y2 := 0
w := 0

while (x2 + y2 ≤ 4 and iteration < max_iteration) do
    x := x2 - y2 + x0
    y := w - x2 - y2 + y0
    x2 := x × x
    y2 := y × y
    w := (x + y) × (x + y)
    iteration := iteration + 1
```

## Fix
- `./fractol [fractal name] [window width] [window height]`
- width and height cannot be < 100
- Currently way too slow and need to change colours
- fix zoom, re-renders entire fractal, need to do a quick render, and it needs to zoom at the mouse location, not middle
- use strcmp for the argv

## Repos to look at (copy)
[Librity](https://github.com/librity/ft_fractol)

[Enrique](https://github.com/EnriqueSLeeK/fract-ol)

[Shawtanap](https://github.com/shwatanap/fract-ol/tree/main/srcs)

# Result
<img width="2040" alt="image" src="https://user-images.githubusercontent.com/94874173/190076734-4c120e18-ca77-4699-a81b-be46b0ba20cf.png">
125 / 100
