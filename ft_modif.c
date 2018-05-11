 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:59:33 by lballiot          #+#    #+#             */
/*   Updated: 2018/04/26 16:51:37 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int deal_key(int key, void **param)
{
	(void)param;
    if (key == 53)
	{
//		mlx_destroy_window()
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
	int width;
	int height;
	int err;

	err = 0;
	width = ((data->zoom + 1) * (data->len + 20) * 2 );
	height = ((data->zoom + 1) * (data->height + 20) *2);
	if (((data->zoom + 1) * data->height) > 1300 || ((data->zoom + 1) * data->len) > 2500)
	{
		height = 1300;
		width = 2500;
		err = 1;
	}
	if (err == 1)
		data->zoom = 15;
	data->window = mlx_new_window(data->mlx_ptr, width, height, data->av);// open window to see the map
	mlx_key_hook(data->window, deal_key, (void *)&data);
	(void)coord;
}
