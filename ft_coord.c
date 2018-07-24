/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:50:48 by lballiot          #+#    #+#             */
/*   Updated: 2018/06/29 10:27:10 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fill_elem(t_coord **e, t_file data)
{
	(*e)->point[0] = data.t[0] * data.zoom + data.space_y;
	(*e)->point[1] = data.t[1] * data.zoom + data.space_y;
	(*e)->point[2] = data.t[2] * data.evelation;
	(*e)->right[0] = data.t[3] * data.zoom + data.space_y;
	(*e)->right[1] = data.t[4] * data.zoom + data.space_y;
	(*e)->right[2] = data.t[5] * data.evelation;
	(*e)->down[0] = data.t[6] * data.zoom + data.space_y;
	(*e)->down[1] = data.t[7] * data.zoom + data.space_y;
	(*e)->down[2] = data.t[8] * data.evelation;
	(*e)->next = NULL;
}

t_coord			*ft_add_coord(t_coord *coord, t_file data)
{
	t_coord			*e;
	static t_coord	*tmp;

	if (!(e = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	fill_elem(&e, data);
	isometrie(&e);
	if (coord == NULL)
	{
		coord = e;
		tmp = coord;
		data.tmp = tmp;
	}
	else
	{
		while (coord->next != NULL)
			coord = coord->next;
		coord->next = e;
	}
	coord = tmp;
	return (coord);
}

void			change_neg(t_file *data)
{
	// if altitude (= z) modifier  
//	if (t[2] < 100000)
	printf("YOYOYOYOYOY\n%d\n", data->t[0]);
	printf("%d\n", data->t[1]);
	printf("%d\n", data->t[2]);
	printf("%d\n", data->t[3]);
	printf("%d\n", data->t[4]);
	printf("%d\n", data->t[5]);
	printf("%d\n", data->t[6]);
	printf("%d\n", data->t[7]);
	printf("%d\nYOYOYOYOYO\n", data->t[8]);
}

void			fill_tab_int(t_file *data)
{
	int x;

	x = data->i;
	data->t[0] = x + data->space_x;
	data->t[1] = data->y;
	data->t[2] = ft_atoi(data->split[x]);
	if (data->split[x + 1] != NULL)
	{
		data->t[3] = x + 1 + data->space_x;
		data->t[4] = data->y;
		data->t[5] = ft_atoi(data->split[x + 1]);
	}
	if (data->down && data->down[x] != NULL)
	{
		data->t[6] = x + data->space_x;
		data->t[7] = data->y + 1;
		data->t[8] = ft_atoi(data->down[x]);
	}
	else
	{
		data->i = x;
		fill_end_tab(data);
	}
//	change_neg(data);
}

void			ft_coord2(t_file *sct)
{
	if (sct->tab[sct->y][ft_strlen(sct->tab[sct->y]) - 1] == ' ')
		sct->tab[sct->y][ft_strlen(sct->tab[sct->y]) - 1] = '\0';
	if (sct->tab[sct->y])
	{
		ft_putstr("E");
		sct->split = ft_strsplit(sct->tab[sct->y], ' '); //crash ici /!\/
		ft_putstr("Q");
	}
	ft_putstr("P");
	if (sct->tab[sct->y + 1] != NULL)
	{
		if (sct->down != NULL)
			free(sct->down);
		if (sct->tab[sct->y + 1][ft_strlen(sct->tab[sct->y + 1]) - 1] == ' ')
			sct->tab[sct->y + 1][ft_strlen(sct->tab[sct->y + 1]) - 1] = '\0';
		sct->down = ft_strsplit(sct->tab[sct->y + 1], ' ');
	}
//		ft_putstr("lalal\n");
}

t_coord			*ft_coord(t_file *data, t_coord *coord)
{
	data->i = -1;
	data->y = -1;
	data->split = NULL;
	data->down = NULL;
	ft_putstr("#");
	while (data->tab[++data->y] != NULL)
	{
		ft_putstr("B");
		ft_coord2(data);
		ft_putstr("R");
		while (data->split[++data->i] != NULL)
		{
			fill_tab_int(data);
			coord = ft_add_coord(coord, *data);
		}
		remove_tab(data->split);
		data->i = 0;
		if (data->down && data->down[0])
			while (data->down[data->i])
				ft_strdel(&data->down[data->i++]);
			data->i = -1;
		}
		if (data->down != NULL)
			free(data->down);
		*data = ft_min_max(coord, data);
		return (coord);
	}
