/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:50:48 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/17 12:50:59 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_file		ft_min_max(t_coord *coord, t_file *data)
{
	data->min_x = coord->point[0];
	data->min_y = coord->point[1];
	data->max_x = coord->point[0];
	data->max_y = coord->point[1];
	while (coord->next != NULL)
	{
		if (coord->point[0] < data->min_x)
			data->min_x = coord->point[0];
		if (coord->point[0] > data->max_x)
			data->max_x = coord->point[0];
		if (coord->point[1] < data->min_y)
			data->min_y = coord->point[1];
		if (coord->point[1] > data->max_y)
			data->max_y = coord->point[1];
		coord = coord->next;
	}
	coord = data->tmp;
	return (*data);
}

void	isometrie(t_coord **e)
{
	(*e)->point[0] = (float)(((0.07 * (float)(*e)->point[0] - 0.07 * (float)(*e)->point[1])) * 3 + 200 );
	(*e)->point[1] = (float)(((0.04 * (float)(*e)->point[0] + 0.04 * (float)(*e)->point[1]) - 0.2 * (float)(*e)->point[2]) * 3 + 200 );
	(*e)->right[0] = (float)(((0.07 * (float)(*e)->right[0] - 0.07 * (float)(*e)->right[1])) * 3 + 200 );
	(*e)->right[1] = (float)(((0.04 * (float)(*e)->right[0] + 0.04 * (float)(*e)->right[1]) - 0.2 * (float)(*e)->right[2]) * 3 + 200 );
	(*e)->down[0] = (float)(((0.07 * (float)(*e)->down[0] - 0.07 * (float)(*e)->down[1])) * 3 + 200 );
	(*e)->down[1] = (float)(((0.04 * (float)(*e)->down[0] + 0.04 * (float)(*e)->down[1]) - 0.2 * (float)(*e)->down[2]) * 3 + 200 );
}

void		fill_elem(t_coord **e, t_file data)
{
	(*e)->point[0] = data.t[0] * data.zoom + data.space_y; 
	(*e)->point[1] = (data.t[1]) * data.zoom + data.space_y ; //* 150;
	(*e)->point[2] = data.t[2] * data.evelation;
	(*e)->right[0] = (data.t[3])* data.zoom + data.space_y; //* 150; 
	(*e)->right[1] = (data.t[4]) * data.zoom + data.space_y; //* 150;
	(*e)->right[2] = data.t[5] * data.evelation;;
	(*e)->down[0] = (data.t[6]) * data.zoom + data.space_y; //* 150; 
	(*e)->down[1] = (data.t[7]) * data.zoom + data.space_y; //* 150;
	(*e)->down[2] = data.t[8] *  data.evelation;;
	(*e)->next = NULL;

}

t_coord		*ft_add_coord(t_coord *coord, t_file data)
{
	t_coord *e;
	static t_coord *tmp;

	if (!(e=(t_coord *)malloc(sizeof(t_coord))))
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

t_coord		*ft_coord(t_file *data, t_coord *coord)
{
	int y = -1;
	int x = 0;
	char **tab_split = NULL;
	char **tab_down = NULL;
	
	y = 0;
	while(data->tab[y] != NULL)
	{
		tab_split = ft_strsplit(data->tab[y], ' ');
		if (data->tab[y + 1] != NULL)
			tab_down = ft_strsplit(data->tab[y + 1], ' ');
		while(tab_split[x] != NULL)
		{
			data->t[0] = x + data->space_x; // x
			data->t[1] = y; // y
			data->t[2] = ft_atoi(tab_split[x]); // z
			if (tab_split[x + 1] != NULL)
			{
				data->t[3] = x + 1 + data->space_x; // x_right
				data->t[4] = y ; // y_right
				data->t[5] = ft_atoi(tab_split[x + 1]); //z_right
			}
			if (tab_down[x] != NULL)
			{
				data->t[6] = x + data->space_x;//x_down
				data->t[7] = y + 1;//y_down
				data->t[8] = ft_atoi(tab_down[x]);//z_down
			}
			else
			{
				data->t[6] = x + data->space_x;//x_down
				data->t[7] = y;//y_down
				data->t[8] = ft_atoi(tab_split[x]);//z_down
				tab_down[x + 1] = NULL;
			}
			coord = ft_add_coord(coord, *data); 
			x++;
		}
		ft_memdel((void *)tab_down);
		free(tab_split);
		x = 0;
		y++;
	}
	*data = ft_min_max(coord, data);
	return (coord);
}


//	printf("\nFT_COORD\ndata.space_x = %d\tdata.space_y = %d\ndata.zoom = %d\n", data->space_x, data->space_y, data->zoom);
