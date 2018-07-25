/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:36:27 by lballiot          #+#    #+#             */
/*   Updated: 2018/06/21 12:05:26 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_file			ft_read_check_map(int fd, t_file data)
{
	char	*map;
	char	*line;
	int		ret;

	data.tab = NULL;
	line = NULL;
	map = ft_strnew(1);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		line = ft_add_back_n(line);
		map = ft_strjoin_and_free(map, line);
		ft_strdel(&line);
		ft_check_char(map);
	}
	map[ft_strlen(map) - 1] = '\0';
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

t_file			init_struct(void)
{
	t_file	data;

	if (!(data.mlx_ptr = mlx_init()))
		exit(EXIT_FAILURE);
	data.split = NULL;
	data.down = NULL;
	data.y = -1;
	data.window = NULL;
	data.tab = NULL;
	data.len_map = 0;
	data.height_map = 0;
	data.zoom = 100;
	data.min_x = 0;
	data.min_y = 0;
	data.max_x = 0;
	data.max_y = 0;
	data.i = -1;
	data.space_x = 5;
	data.space_y = 5;
	data.tmp = NULL;
	data.evelation = 20;
	while (data.i < 9)
		data.t[++data.i] = 0;
	data.i = 0;
	return (data);
}

t_file			ft_do_tab(int ac, char *av)
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
	data = init_struct();
	data = ft_read_check_map(fd, data);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Close failed\n", 2);
		exit(EXIT_FAILURE);
	}
	return (data);
}

void			begin_bressen(t_coord *coord, t_file data)
{
	t_coord *tmp;

	tmp = coord;
	while (coord->next != NULL)
	{
		ft_bresen(data, coord, 1);
		ft_bresen(data, coord, 0);
		coord = coord->next;
	}
	coord = tmp;
}

int				main(int ac, char **av)
{
	t_file		data;
	t_coord		*coord;

	coord = NULL;
	data = ft_do_tab(ac, av[1]);
	data.av = ft_strdup(av[1]);
	if (data.tab[0] == NULL)
		exit(EXIT_FAILURE);
	coord = ft_coord(&data, coord);
	if (coord == NULL)
		exit(EXIT_FAILURE);
	coord = ft_modification(&data, coord);
	if (coord)
	{
		begin_bressen(coord, data);
	}
	remove_tab(data.tab);
	if (coord)
		remove_lst(coord);
	mlx_key_hook(data.window, deal_key, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
