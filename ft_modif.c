 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:59:33 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/14 15:49:47 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int deal_key(int key, void **param)
{
	(void)param;
    if (key == 53)
	{
//		mlx_destroy_window(*mlx_ptr, *window)
        exit(EXIT_FAILURE);
	}
// if key == 69 zoom-in
// if key == 78 zoom-out
//    ft_putstr("key touch\n");
//    ft_putnbr(key);
//    ft_putchar('\n');
//  ft_putstr("param\n");
//  printf("%d", param.len);
//    ft_putchar('\n');
    return (0);
}

void	ft_modification(t_file *data, t_coord *coord)
{
	//printf("\nMODIF\n");
	data->width_win = (data->zoom + 1) * data->len;
	data->height_win = (data->zoom + 1) * data->height;
	if (data->height_win > 1300)
		data->height_win = 1395;
	if (data->width_win > 2500)
		data->width_win = 2560;
	if (data->window == NULL)
		data->window = mlx_new_window(data->mlx_ptr, data->width_win, data->height_win, data->av);
	//printf("data->width_win = %d\tdata->height_win = %d\n", data->width_win, data->height_win);
	//printf("min_x = %d\tmin_y = %d\nmax_x = %d\tmax_y = %d\n", data->min_x, data->min_y, data->max_x, data->max_y);
// modification zoom and centre
	if (data->min_x < 0)
	{
		data->space_x = -data->min_x + 10;
		//printf("\nCONDITION\ndata.space_x = %d\n", data->space_x);
	}
	if (data->min_y < 0)
	{
		data->space_y = -data->min_y * 50;//-data->min_y * data->zoom;
		//printf("\nCONDITION\ndata.space_y = %d\n", data->space_y);
	}
	//printf("min_x = %d\tmin_y = %d\nmax_x = %d\tmax_y = %d\n", data->min_x, data->min_y, data->max_x, data->max_y);
	if (data->max_x > data->width_win || data->max_y > data->height_win)
	{
		ft_putstr("diminution data.zoom\n");
		data->zoom -= 10;
	}

	if (data->space_x > 0 || data->space_y > 0 || data->max_x > data->width_win || data->max_y > data->height_win)
	{
		ft_putstr("coord=ft_coord\n\n");
		coord = ft_coord(data, coord);
	}
//		if (max_x > data->width_win || max_y > data->height_win)
			// data.zoom--;


//	coord = ft_coord(*data, coord);
	//printf("data->zoom = %d\nEND MODIF\n", data->zoom);



	mlx_key_hook(data->window, deal_key, (void *)&data);
	(void)coord;
}
