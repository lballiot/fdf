 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:59:33 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/11 12:24:04 by lballiot         ###   ########.fr       */
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
	int width;
	int height;

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
	
    while (coord->next != NULL)
    {
        coord = coord->next;
	}
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
	

	width = (data->zoom + 1) * data->len;
	height = (data->zoom + 1) * data->height;
	if (height > 1300)
		height = 1395;
	if (width > 2500)
		width = 2560;
	printf("width = %d\theight = %d\n", width, height);
	data->window = mlx_new_window(data->mlx_ptr, width, height, data->av);
// modif zoom
	mlx_key_hook(data->window, deal_key, (void *)&data);
	(void)coord;
}
