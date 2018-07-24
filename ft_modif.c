/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:59:33 by lballiot          #+#    #+#             */
/*   Updated: 2018/07/24 15:05:08 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			deal_key(int key, t_file *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->window);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void		size_window(t_file *data)
{
	data->width_win = 110 * data->len_map;
	data->height_win = 110 * data->height_map;
	if (data->height_win > 1300)
		data->height_win = 1390;
	if (data->width_win > 2500)
		data->width_win = 2560;
	if (data->height_win < 700)
		data->height_win = 700;
	if (data->width_win < 700)
		data->width_win = 700;
}

t_coord		*placement(t_file *data, t_coord *coord)
{
	if (data->min_y < 10 && data->max_y < data->height_win - 10)
		data->space_y += 10;
	if (data->min_x < 0 && data->max_x < data->width_win)
	{
		if (data->max_x + 100 < data->width_win)
			data->space_x += 100;
		else if (data->max_x + 50 < data->width_win)
			data->space_x += 50;
		else if (data->max_x + 10 < data->width_win)
			data->space_x += 10;
	}
	remove_lst(coord);
	coord = NULL;
	ft_putstr("3");
	return (ft_modification(data, ft_coord(data, coord)));
}

t_coord		*param(t_file *data, t_coord *coord)
{
	if ((data->max_x > data->width_win || data->max_y > data->height_win)
		&& data->zoom > 5)
	{
		if (data->min_y < 0 && data->evelation >= 20)
		{
			data->evelation = data->evelation / 2;
			if (data->min_y < -100000 || data->max_y > 100000)
				data->evelation = 2;
			remove_lst(coord);
			coord = NULL;
			ft_putstr("1");
			return (ft_modification(data, ft_coord(data, coord)));
		}
		if (data->zoom > 10)
			data->zoom -= 10;
		remove_lst(coord);
		coord = NULL;
//		ft_putstr("2");
		return (ft_modification(data, ft_coord(data, coord)));
	}
/*	if (data->min_y < 0 && data->evelation >= 20)
	{
		data->evelation = data->evelation / 2;
		if (data->min_y < -100000 || data->max_y > 100000)
			data->evelation = 2;
		remove_lst(coord);
		coord = NULL;
		ft_putstr("1");
		return (ft_modification(data, ft_coord(data, coord)));
	}*/
	return (coord);
}

t_coord		*ft_modification(t_file *data, t_coord *coord)
{
	size_window(data);
//	printf("longueur fenetre = %d\tlargeur fenetre = %d\nmax x = %d\tmin x = %d\tmax y = %d\tmin y = %d\n", data->height_win, data->width_win, data->max_x, data->min_x, data->max_y, data->min_y);

	if ((data->min_x < 0 && data->max_x < data->width_win) ||
		(data->min_y < 10 && data->max_y < data->height_win - 10))
		coord = placement(data, coord);
	if ((data->min_x < 0 || data->min_y < 0) ||
		((data->max_x > data->width_win || data->max_y > data->height_win) &&
			data->zoom > 20))
		coord = param(data, coord);
	ft_putstr("UUTUT\n");
	if(!data->window)
		data->window = mlx_new_window(data->mlx_ptr, data->width_win,
			data->height_win, data->av);
	mlx_key_hook(data->window, deal_key, data);
	ft_putstr("ENDNENENENENENENED\n");
	return (coord);
}
