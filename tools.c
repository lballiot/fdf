/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 10:25:45 by lballiot          #+#    #+#             */
/*   Updated: 2018/06/29 10:25:55 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			isometrie(t_coord **e)
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

void			remove_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i++]);
	}
	free(tab);
	tab = NULL;
}

void			remove_lst(t_coord *coord)
{
	t_coord *tmp;

	tmp = coord;
	while (tmp->next)
	{
		coord = tmp->next;
		free(tmp);
		tmp = coord;
	}
	free(tmp);
	tmp = NULL;
	coord = NULL;
}

void			fill_end_tab(t_file *data)
{
	data->t[6] = data->i + data->space_x;
	data->t[7] = data->y;
	data->t[8] = ft_atoi(data->split[data->i]);
	if (data->down && data->down[data->i])
		data->down[data->i + 1] = NULL;
}
