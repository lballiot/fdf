 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:59:33 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/15 18:16:37 by lballiot         ###   ########.fr       */
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
	printf("\nMODIF\n");
	data->width_win = (data->zoom + 1) * data->len;
	data->height_win = (data->zoom + 1) * data->height;
	if (data->height_win > 1300)
		data->height_win = 1395;
	if (data->width_win > 2500)
		data->width_win = 2560;
	if (data->max_x > data->width_win || data->max_y > data->height_win)
	{
//		data->space_x -= 5;
//		if (data->min_y < 0)
			
		ft_putstr("diminution data.zoom\n");
		data->zoom -= 50;
//		if (data->space_x > 1000)
//			data->zoom = 50;
		coord = ft_coord(data, coord);
	}
	if (data->min_x < 0)
	{
		data->space_x += -data->min_x;
		printf("\nCONDITION\ndata.space_x = %d\n", data->space_x);
	}
	if (data->min_y < 0)
	{
		data->space_y = -data->min_y + data->height_win;
		printf("\nCONDITION\ndata.space_y = %d\n", data->space_y);
	}
	//printf("min_x = %d\tmin_y = %d\nmax_x = %d\tmax_y = %d\n", data->min_x, data->min_y, data->max_x, data->max_y);
	if (data->min_x < 0 || data->min_y < 0 || data->max_x > data->width_win || data->max_y > data->height_win)
	{
		ft_putstr("coord=ft_coord\n\n");
		coord = NULL;
		coord = ft_coord(data, coord);
//		return (coord = ft_coord(data, coord));
	}

//	ft_putstr("apres return(ft_coord)\n");

/*	ft_putstr("COOORD BEFORE WINDOW\n");
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

	data->window = mlx_new_window(data->mlx_ptr, data->width_win, data->height_win, data->av);
	//printf("min_x = %d\tmin_y = %d\nmax_x = %d\tmax_y = %d\n", data->min_x, data->min_y, data->max_x, data->max_y);


	printf("data->zoom = %d\nEND MODIF\n", data->zoom);



	mlx_key_hook(data->window, deal_key, (void *)&data);
	return (coord);
}
