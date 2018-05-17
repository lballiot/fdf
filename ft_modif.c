 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:59:33 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/17 12:36:46 by lballiot         ###   ########.fr       */
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

t_coord	*ft_modification(t_file *data, t_coord *coord)
{
//	printf("\nMODIF\n");
//	printf("data->zoom = %d\n", data->zoom);
	data->width_win = (100 + 10) * data->len;//(data->zoom + 10) * data->len;
	data->height_win = (100 + 10) * data->height;//(data->zoom + 10) * data->height;
	if (data->height_win > 1300)
		data->height_win = 1390;
	if (data->width_win > 2500)
		data->width_win = 2560;
		if (data->height_win < 700)
		data->height_win = 700;
	if (data->width_win < 700)
		data->width_win = 700;



// WHILE THE MAPS HAVN'T THE GOOD ZOOM DATA.SPACE_X AND Y DON'T MOVE 

	if (data->min_x < 0 && data->max_x < data->width_win)
	{
		if (data->max_x + 100 < data->width_win)//
			data->space_x += 100;
		else if (data->max_x  + 50< data->width_win)//
			data->space_x += 50;//
		else if (data->max_x + 10 < data->width_win)//
			data->space_x += 10;//
		coord = NULL;
		return (ft_modification(data, ft_coord(data, coord)));
	}
	if (data->min_y < 10 && data->max_y < data->height_win - 10)
	{
		data->space_y += 10;
		coord = NULL;
		return (ft_modification(data, ft_coord(data, coord)));
	}
	if ((data->min_x < 0 || data->min_y < 0) || ((data->max_x > data->width_win || data->max_y > data->height_win) && data->zoom > 20))
	{
		if ((data->max_x > data->width_win || data->max_y > data->height_win) && data->zoom > 10)
		{
			data->zoom -= 10;
			coord = NULL;
			return (ft_modification(data,ft_coord(data, coord)));
		}
		if ((data->max_x > data->width_win || data->max_y > data->height_win) && data->zoom > 5)
		{
			data->zoom--;
			coord = NULL;
			return (ft_modification(data,ft_coord(data, coord)));
		}
		else if (data->min_y < 0 && data->evelation >= 20)
		{
			data->i = 1;
			data->evelation -= 10;
			coord = NULL;
			return (ft_modification(data,ft_coord(data, coord)));
		}
	}

	if (data->i == 1)
		if (data->height_win < 1300)
			data->height_win = 1390;
	data->window = mlx_new_window(data->mlx_ptr, data->width_win, data->height_win, data->av);
	//printf("min_x = %d\tmin_y = %d\nmax_x = %d\tmax_y = %d\n", data->min_x, data->min_y, data->max_x, data->max_y);


//	printf("data->zoom = %d\nEND MODIF\n", data->zoom);



	mlx_key_hook(data->window, deal_key, (void *)&data);
	return (coord);
}
