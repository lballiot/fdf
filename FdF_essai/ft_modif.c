/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:59:33 by lballiot          #+#    #+#             */
/*   Updated: 2018/04/20 14:40:21 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int deal_key(int key, void **param)
{
	(void)param;
    if (key == 53)
        exit(EXIT_FAILURE);
// if key == 69 zoom-in
// if key == 78 zoom-out
    ft_putstr("key touch\n");
    ft_putnbr(key);
    ft_putchar('\n');
    ft_putstr("param\n");
//  printf("%d", param.len);
    ft_putchar('\n');
    return (0);
}

void	ft_modification(t_file *data, t_coord *coord)
{
	int width;
	int height;

	width = (data->len + 10) * data->zoom;
	height = (data->height + 10) * data->zoom;
	ft_putstr("largeur = ");
	ft_putnbr(width);
	ft_putchar('\n');
	if (width > 2560)
		width = 2560;
	if (height > 1395)
		height = 1395;
	data->window = mlx_new_window(data->mlx_ptr, width, height, data->av);// open window to see the map
	mlx_key_hook(data->window, deal_key, (void *)&data);
	(void)coord;
}
