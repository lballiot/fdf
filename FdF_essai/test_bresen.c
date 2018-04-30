#include "fdf.h"

void    ft_bresen(t_file data, t_coord *coord)
{
    int dx;
    int dy;
    int e;
	int xa;
	int xb;
	int ya;
	int yb;

	xa = coord->point[0];
	xb = coord->right[0];
	ya = coord->point[1];
	yb = coord->right[1];
    e = xb - xa;
    dx = e * 2;
    dy = (yb - ya) * 2;
    while (xa <= xb)
    {
        mlx_pixel_put(data.mlx_ptr, data.window, xa, ya, 0xFE0000);
        xa++;
        if ((e = e + dx) <= 0)
        {
            ya++;
            e = e + dx;
        }
    }
    mlx_pixel_put(data.mlx_ptr, data.window, xa, ya, 0xFE0000);
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
