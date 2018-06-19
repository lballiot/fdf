/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:36:27 by lballiot          #+#    #+#             */
/*   Updated: 2018/06/19 19:11:33 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_file			ft_read_check_map(int fd, t_file data)
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
	printf("%s\n", map);//
	if (ret == 0 && map[0] == '\0')
	{
		ft_putstr_fd("Map invalid : nothing to read\n", 2);
		free(map); //
		exit(EXIT_FAILURE);
	}
//	data = ft_check_map(map, data);
	data.tab = ft_strsplit(map, '\n'); // 1 leaks
	data.tab[data.height_map] = NULL;
	free(map);
	return (data);
}

t_file			init_struct(char *av)
{
	t_file	data;
	int		i;

	i = -1;
	if (!(data.mlx_ptr = mlx_init()))
		exit(EXIT_FAILURE);
	data.window = NULL;
	data.av = ft_strdup(av); //leaks 1 see in modification
	free(data.av);//
	data.tab = NULL;
	data.len_map = 0;
	data.height_map = 0;
	data.zoom = 100;
	data.min_x = 0;
	data.min_y = 0;
	data.max_x = 0;
	data.max_y = 0;
	data.i = 0;
	data.space_x = 5;
	data.space_y = 5;
	data.tmp = NULL;
	data.evelation = 20;
	while (i < 9)
		data.t[++i] = 0;
	return (data);
}

t_file			ft_do_tab(int ac, char *av) //no leaks
{
	int		fd;
	t_file	data;

	if (ac != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename> [ map ]\n", 2);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(av, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Open failed : please use an existing file\n", 2);
		exit(EXIT_FAILURE);
	}
	data = init_struct(av);
	data = ft_read_check_map(fd, data);
	if (close(fd) == -1)
	{
		free(&data);
		ft_putstr_fd("Close failed\n", 2);
		exit(EXIT_FAILURE);
		}
	return (data);
}

int				main(int ac, char **av)
{
	t_file	data;
	t_coord *coord;

	coord = NULL;
	data = ft_do_tab(ac, av[1]);
/*	if (data.tab[0] == NULL)
		exit(EXIT_FAILURE);
	coord = ft_coord(&data, coord);
	if (coord == NULL)
		exit(EXIT_FAILURE);
	coord = ft_modification(&data, coord);
	ft_memdel((void *)data.tab);
	if (coord)
		while (coord->next != NULL)
		{
			if (coord->next)
			{
				ft_bresen(data, coord, 1);
				ft_bresen(data, coord, 0);
			}
			coord = coord->next;
		}
/////////////////////////////
	t_coord *tmp;
	while (coord->next)
	{
		tmp = coord->next;
		free(coord);
		coord = tmp;
	}
	free(coord);
	coord = NULL;
////////////////////////////*/
	mlx_loop(data.mlx_ptr);
	return (0);
}
