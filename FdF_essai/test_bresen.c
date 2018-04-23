#include "fdf.h"

void    ft_bresen(int xa, int xb, int ya, int yb, char *av)
{
    void *mlx_ptr;
    void *window;

    mlx_ptr = mlx_init();
    window = mlx_new_window(mlx_ptr, 500, 500, av);
    mlx_pixel_put(mlx_ptr, window, xa, ya, 0xFE0000); //point A
    mlx_pixel_put(mlx_ptr, window, xb, yb, 0xFE0000); // point B
    int dx;
    int dy;
    int e;

    e = xb - xa;
    dx = e * 2;
    dy = (yb - ya) * 2;
    while (xa <= xb)
    {
        mlx_pixel_put(mlx_ptr, window, xa, ya, 0xFFFFFF);
        xa++;
        if ((e = e + dx) <= 0)
        {
            ya++;
            e = e + dx;
        }
    }
    mlx_pixel_put(mlx_ptr, window, xa, ya, 0xFFFFFF);
    mlx_loop(mlx_ptr);
}


 /*void ft_bresen(int xa, int xb, int ya, int yb, char *av)
{
    void *mlx_ptr;
    void *window;

    mlx_ptr= mlx_init();
    window = mlx_new_window(mlx_ptr, 500, 500, av);

    int dx;
    int dy;
    if ((dx = xb - xa) != 0)
    {
        if (dx > 0)
			if (dy > 0)
				//vecteur oblique dans le 1er cadran
			}


    mlx_pixel_put(mlx_ptr, window, xa, ya, 0xFFFFFF);
    mlx_loop(mlx_ptr);
}
 */
