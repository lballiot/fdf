/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:36:27 by lballiot          #+#    #+#             */
/*   Updated: 2018/04/23 17:09:01 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_file		ft_read_check_map(int fd, t_file data)
{
	char	*map;
	char	*line;
	int		ret;

	data.tab = NULL;
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
	data = ft_check_map(map, data);
	data.tab = ft_strsplit(map, '\n');
	free(map);
	return (data);
}

t_file		ft_do_tab(int ac, char *av, t_file data)
{
	int fd;

	if (ac != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename> [ map ]\n", 2);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(av, O_RDONLY)) == -1)
	{
		ft_putstr_fd("Open failed : please use an existing file\n", 2);
		exit(EXIT_FAILURE);
	}
	data = ft_read_check_map(fd, data);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Close failed\n", 2);
		exit(EXIT_FAILURE);
	}
	return (data);
}

t_file		init_struct(char *av)
{
	t_file data;

	data.mlx_ptr = mlx_init(); //init obligatory 
	data.window = NULL;
	data.av = ft_strdup(av);
	data.tab = NULL;
	data.len = 0;
	data.height = 0;
	data.zoom = 20;
	return (data);
}

void	ft_test_grid(t_file data, t_coord *coord)
{
	while (data.len > 0)
	{
		mlx_pixel_put(data.mlx_ptr, data.window, (coord->point[0] * data.zoom), (coord->point[1] * data.zoom), 0x0008FE);
		coord->point[1]--;
		data.len--;
	}

}

void    ft_bresen(int xa, int xb, int ya, int yb, char *av);

int		main(int ac, char **av)
{
	t_file data; // ptr window mlx and other data needed
	t_coord *coord = NULL;

	data = init_struct(av[1]);
	data = ft_do_tab(ac, av[1], data);
	coord = ft_coord(data, coord); // for find the coordonne of x, y, z
//  print the maps after modification for the zoom and the placement of the maps
	ft_modification(&data, coord); 
	while (coord->next != NULL)
	{
		mlx_pixel_put(data.mlx_ptr, data.window, (coord->point[0] * data.zoom), (coord->point[1] * data.zoom), 0xFFFFFF);
		coord = coord->next;
	}
	mlx_pixel_put(data.mlx_ptr, data.window, (coord->point[0] * data.zoom), (coord->point[1] * data.zoom), 0xFE0000);
//	ft_bresen(coord->point[0], coord->right[0], coord->point[1], coord->right[1], av[1]);
//	ft_test_grid(data, coord);
//	mlx_pixel_put(data.mlx_ptr, data.window, (coord->point[0] * data.zoom), (coord->point[1] * data.zoom), 0xFE0000);
//	mlx_pixel_put(data.mlx_ptr, data.window, (coord->right[0] * data.zoom), (coord->right[1] * data.zoom), 0xFFFFFF);
	ft_putstr("len = ");
	ft_putnbr(data.len);
	ft_putstr("\nheight = ");
	ft_putnbr(data.height);
	mlx_loop(data.mlx_ptr);
	return (0);
}


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

to print the list 
        ft_putstr("x = ");
        ft_putnbr(coord->point[0]);
        ft_putstr("\ny = ");
        ft_putnbr(coord->point[1]);
        ft_putstr("\nz = ");
        ft_putnbr(coord->point[2]);
        ft_putstr("\nx = ");
        ft_putnbr(coord->right[0]);
        ft_putstr("\ny = ");
        ft_putnbr(coord->right[1]);
        ft_putstr("\nz = ");
        ft_putnbr(coord->right[2]);
        ft_putstr("\nx = ");
        ft_putnbr(coord->down[0]);
        ft_putstr("\ny = ");
        ft_putnbr(coord->down[1]);
        ft_putstr("\nz = ");
        ft_putnbr(coord->down[2]);
        ft_putstr("\n");
		ft_putstr("endendnednedend\n");


*/
