#include <mlx.h>
#include <fcntl.h>
#include "libft/libft.h"

int main(int ac, char **av)
{
    void *mlx_ptr;
    void *window;
//	int x = 100;
//	int y = 100;

    if (ac != 2)
    {
        ft_putstr("Usage : ./fdf <filename> [ map ]\n");
        exit(EXIT_FAILURE);
    }
    mlx_ptr = mlx_init(); // init obligatory
    window = mlx_new_window(mlx_ptr, 500, 500, av[1]); // open window to see the map
	mlx_loop(mlx_ptr);
	return (0);
}
