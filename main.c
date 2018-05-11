/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:36:27 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/11 12:25:07 by lballiot         ###   ########.fr       */
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
	data.tab[data.height] = NULL;
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

t_file		init_struct(char *av)
{
	t_file data;

	if (!(data.mlx_ptr = mlx_init()))
		exit(EXIT_FAILURE);
	data.window = NULL;
	data.av = ft_strdup(ft_title(av));
	data.tab = NULL;
	data.len = 0;
	data.height = 0;
	data.zoom = 100;
	return (data);
}

t_file		ft_do_tab(int ac, char *av)
{
	int fd;
	t_file data;

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



int			main(int ac, char **av)
{
	t_file	data; // ptr window mlx and other data needed
	t_coord *coord;

	coord = NULL;
	data = ft_do_tab(ac, av[1]);
	coord = ft_coord(data, coord);
	ft_memdel((void *)data.tab);
//  print the maps after modification for the zoom and the placement of the maps
	ft_modification(&data, coord);
	while (coord->next != NULL)
	{
		ft_bresen(data, coord);
		coord = coord->next;
	}
	ft_bresen(data, coord);
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
