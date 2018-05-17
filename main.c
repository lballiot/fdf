/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:36:27 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/17 14:49:22 by lballiot         ###   ########.fr       */
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
	if (ret == 0 && map[0] == '\0')
	{
		ft_putstr_fd("Map invalid : nothing to read\n", 2);
		exit(EXIT_FAILURE);
	}
	data = ft_check_map(map, data);
	data.tab = ft_strsplit(map, '\n');
	data.tab[data.height_map] = NULL;
	free(map);
	return (data);
}

static char		*ft_title(char *str)
{
	char	*cpy;
	int		i;
	int		j;
	int		k;

	i = -1;
	cpy = ft_strrev(str);
	while (cpy[++i])
		if (str[i] == '/')
		{
			j = ft_strlen(str) - 1 - i;
			k = i + 1;
		}
	free(cpy);
	cpy = ft_strnew(j + 1);
	i = 0;
	while (j--)
		cpy[i++] = str[k++];
	return (cpy);
}

t_file			init_struct(char *av)
{
	t_file	data;
	int		i;

	i = -1;
	if (!(data.mlx_ptr = mlx_init()))
		exit(EXIT_FAILURE);
	data.window = NULL;
	data.av = ft_strdup(ft_title(av));
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

t_file			ft_do_tab(int ac, char *av)
{
	int		fd;
	t_file	data;

	data = init_struct(av);
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
	data = ft_read_check_map(fd, data);
	if (close(fd) == -1)
	{
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
	coord = ft_coord(&data, coord);
	coord = ft_modification(&data, coord);
	ft_memdel((void *)data.tab);
	while (coord->next != NULL)
	{
		if (coord->next)
		{
			ft_bresen(data, coord, 1);
			ft_bresen(data, coord, 0);
		}
		coord = coord->next;
	}
	mlx_loop(data.mlx_ptr);
	return (0);
}

//	printf("x1 = %d \ty1 = %d \tz1 = %d\nx2 = %d \ty2 = %d \tz2 = %d \nx3 = %d \ty3 = %d \tz3 = %d\n\n", coord->point[0], coord->point[1], coord->point[2], coord->right[0], coord->right[1], coord->right[2], coord->down[0], coord->down[1], coord->down[2]);
//	printf("MAIN BEFORE BRESEN\nmin_x = %d\tmin_y = %d\nmax_x = %d\tmax_y = %d\ndata.width_win = %d\tdata.height_win = %d\ndata.zoom = %d\ndata.space_x = %d\tdata.space_y = %d\ndata.evelation = %d\n", data.min_x, data.min_y, data.max_x, data.max_y, data.width_win, data.height_win, data.zoom, data.space_x, data.space_y, data.evelation);
