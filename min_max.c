/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:12:17 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/17 14:30:27 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_file	ft_min_max(t_coord *coord, t_file *data)
{
	data->i = 0;
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
