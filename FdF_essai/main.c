/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:36:27 by lballiot          #+#    #+#             */
/*   Updated: 2018/04/17 17:17:31 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	ft_bresen(int xa, int xb, int ya, int yb, char *av)
{
	void *mlx_ptr;
	void *window;

	mlx_ptr= mlx_init();
	window = mlx_new_window(mlx_ptr, 500, 500, av);
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
*/

void	ft_bresen(int xa, int xb, int ya, int yb, char *av)
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
	}


	mlx_pixel_put(mlx_ptr, window, xa, ya, 0xFFFFFF);
	mlx_loop(mlx_ptr);
}

char **ft_map(int fd)
{
	char *map;
	char *line;
	char **tab = NULL;
	int ret;
	
	line = ft_strnew(1);
	map = ft_strnew(1);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		line = ft_add_back_n(line);
		map = ft_strjoin_and_free(map, line);
		ft_check_char(map); 
	}
	free(line);
	if (ret == 0 && map[0] == '\0')
	{
		ft_putstr_fd("Map invalid : nothing to read\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_check_map(map);
	tab = ft_strsplit(map, '\n');
	free(map);
	return (tab);
}

int		main(int ac, char **av)
{
//	t_file data; ptr window mlx
//	t_coord *coord = NULL;
	char **tab;
	int fd;

	if (ac != 2)
    {
        ft_putstr_fd("Usage : ./fdf <filename> [ map ]\n", 2);
        exit(EXIT_FAILURE);
    }
	fd = open(av[1], O_RDONLY);
	tab = ft_map(fd);
//	coord = ft_coord(tab, coord); // for find the coordonne of x, y, z
	ft_bresen(100, 200, 50, 10, av[1]);
	return (0);
}



/*
	data.mlx_ptr = mlx_init(); // init obligatory
    data.window = mlx_new_window(data.mlx_ptr, 500, 500, av[1]); // open window to see the map
	ft_putstr("titi\n");	
*/


/* to print tab
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}


	while (tab[i])
	{
		ft_putstr("tab[");
		ft_putnbr(i);
		ft_putstr("] = ");
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
*/
