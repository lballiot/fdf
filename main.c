/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:36:27 by lballiot          #+#    #+#             */
/*   Updated: 2018/04/03 15:22:46 by karakhirn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

char **ft_map(int fd)
{
	char *map;
	char *line;
	char **tab = NULL;
	int ret;
//	int i = 0;//
	
	line = ft_strnew(1);
	map = ft_strnew(1);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		line = ft_add_back_n(line);
		map = ft_strjoin_and_free(map, line);
		ft_parser(map); //parser if failed exit failure 
	}
	free(line);
	if (ret == 0 && map[0] == '\0')
	{
		ft_putstr_fd("Map invalid : nothing to read\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_check_map(map);
	tab = ft_strsplit(map, ' ');
	free(map);
	return (tab);
}

int		main(int ac, char **av)
{
//	t_file data; ptr window mlx
	t_coord *coord = NULL;
	char **tab;
	int fd;

	if (ac != 2)
    {
        ft_putstr_fd("Usage : ./fdf <filename> [ map ]\n", 2);
        exit(EXIT_FAILURE);
    }
	fd = open(av[1], O_RDONLY);
	tab = ft_map(fd);
	coord = ft_coord(tab, coord); // for find the coordonne of x, y, z
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
