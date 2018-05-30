/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:50:48 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/21 17:24:18 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		isometrie(t_coord **e)
{
	(*e)->point[0] = (float)(((0.07 * (float)(*e)->point[0] - 0.07 *
							(float)(*e)->point[1])) * 3 + 200);
	(*e)->point[1] = (float)(((0.04 * (float)(*e)->point[0] + 0.04 *
							(float)(*e)->point[1]) - 0.2 *
							(float)(*e)->point[2]) * 3 + 200);
	(*e)->right[0] = (float)(((0.07 * (float)(*e)->right[0] - 0.07 *
							(float)(*e)->right[1])) * 3 + 200);
	(*e)->right[1] = (float)(((0.04 * (float)(*e)->right[0] + 0.04 *
							(float)(*e)->right[1]) - 0.2 *
							(float)(*e)->right[2]) * 3 + 200);
	(*e)->down[0] = (float)(((0.07 * (float)(*e)->down[0] - 0.07 *
							(float)(*e)->down[1])) * 3 + 200);
	(*e)->down[1] = (float)(((0.04 * (float)(*e)->down[0] + 0.04 *
							(float)(*e)->down[1]) - 0.2 *
							(float)(*e)->down[2]) * 3 + 200);
}

void		fill_elem(t_coord **e, t_file data)
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

t_coord		*ft_add_coord(t_coord *coord, t_file data)
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

void		fill_tab_int(t_file *data, int y, char **split, char **down)
{
	int x;

	x = data->i;
	data->t[0] = x + data->space_x;
	data->t[1] = y;
	data->t[2] = ft_atoi(split[x]);
	if (split[x + 1] != NULL)
	{
		data->t[3] = x + 1 + data->space_x;
		data->t[4] = y;
		data->t[5] = ft_atoi(split[x + 1]);
	}
	if (down[x] != NULL)
	{
		data->t[6] = x + data->space_x;
		data->t[7] = y + 1;
		data->t[8] = ft_atoi(down[x]);
	}
	else
	{
		data->t[6] = x + data->space_x;
		data->t[7] = y;
		data->t[8] = ft_atoi(split[x]);
		down[x + 1] = NULL;
	}
}

t_coord		*ft_coord(t_file *data, t_coord *coord)
{
	int		y;
	char	**tab_split;
	char	**tab_down;

	y = -1;
	data->i = -1;
	tab_split = NULL;
	tab_down = NULL;
	while (data->tab[++y] != NULL)
	{
		tab_split = ft_strsplit(data->tab[y], ' ');
		if (data->tab[y + 1] != NULL)
			tab_down = ft_strsplit(data->tab[y + 1], ' ');
		while (tab_split[++data->i] != NULL)
		{
			fill_tab_int(data, y, tab_split, tab_down);
			coord = ft_add_coord(coord, *data);
		}
		ft_memdel((void *)tab_down);
		free(tab_split);
		data->i = -1;
	}
	*data = ft_min_max(coord, data);
	return (coord);
}
