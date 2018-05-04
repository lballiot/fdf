/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 13:55:42 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/04 10:49:21 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_bresen(t_bresen *s, t_coord *coord)
{
	s->x = coord->point[0];
	s->y = coord->point[1];
	s->dx = coord->right[0] - s->x;
	s->dy = coord->right[1] - s->y;
	s->xinc = (s->dx > 0) ? 1 : -1;
	s->yinc = (s->dy > 0) ? 1 : -1;
	s->dx = abs(s->dx);
	s->dy = abs(s->dy);
	s->cumul = 0;
	s->i = 0;
}

void	ft_test(int xi,int yi,int xf,int yf, t_file data)
{
	t_bresen s;

	s.x = xi;
	s.y = yi;
	s.dx = xf - xi;
	s.dy = yf - yi;
	s.xinc = (s.dx > 0) ? 1 : -1;
	s.yinc = (s.dy > 0) ? 1 : -1;
	s.dx = abs(s.dx);
	s.dy = abs(s.dy);
	s.cumul = 0;
	s.i = 0;
//	init_bresen(&s, coord);
	mlx_pixel_put(data.mlx_ptr, data.window, (s.y), (s.x), 0xFFFFFFF);
	if (s.dx > s.dy) //vertical rouge
	{
		s.cumul = s.dx / 2;
		s.i = 0;
		while (++s.i <= s.dx)
		{
			s.x += s.xinc;
			s.cumul -= s.dx;
			if (s.cumul >= s.dx)
			{
				s.cumul -= s.dx;
				s.y += s.yinc;
			}
			mlx_pixel_put(data.mlx_ptr, data.window, (s.y), (s.x), 0xFFFFFF);
		}
	}
	else //horizontal blanc
	{
		s.cumul = s.dy / 2;
		s.i = 0;
		while (++s.i <= s.dy)
		{
			s.y += s.yinc;
			s.cumul += s.dx;
			if (s.cumul >= s.dy)
			{
				s.cumul -= s.dy;
				s.x += s.xinc;
			}
			mlx_pixel_put(data.mlx_ptr, data.window, (s.y), (s.x), 0xFFFFFF);
		}
	}
}

void	ft_bresen(t_file data, t_coord *coord)
{
	(void)data;
	(void)coord;
	ft_test(coord->point[0], coord->point[1], coord->right[0], coord->right[1], data);
	ft_test(coord->point[0], coord->point[1], coord->down[0], coord->down[1], data);
//	init_bresen(&s, coord);
}
