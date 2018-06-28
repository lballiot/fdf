/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 13:55:42 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/17 15:06:28 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_bresen_down(t_bresen *s, t_coord *coord)
{
	s->x = coord->point[0];
	s->y = coord->point[1];
	s->dx = coord->down[0] - coord->point[0];
	s->dy = coord->down[1] - coord->point[1];
	s->xinc = (s->dx > 0) ? 1 : -1;
	s->yinc = (s->dy > 0) ? 1 : -1;
	s->dx = abs(s->dx);
	s->dy = abs(s->dy);
	s->cumul = 0;
	s->i = 0;
}

static void		init_bresen(t_bresen *s, t_coord *coord)
{
	s->x = coord->point[0];
	s->y = coord->point[1];
	s->dx = coord->right[0] - coord->point[0];
	s->dy = coord->right[1] - coord->point[1];
	s->xinc = (s->dx > 0) ? 1 : -1;
	s->yinc = (s->dy > 0) ? 1 : -1;
	s->dx = abs(s->dx);
	s->dy = abs(s->dy);
	s->cumul = 0;
	s->i = 0;
}

void			draw_line(t_file data, t_bresen s)
{
	int color;

	color = 0xffffcc;
	s.cumul = s.dx / 2;
	s.i = 0;
	while (++s.i <= s.dx)
	{
		s.x += s.xinc;
		s.cumul += s.dy;
		if (s.cumul >= s.dx)
		{
			s.cumul -= s.dx;
			s.y += s.yinc;
		}
		mlx_pixel_put(data.mlx_ptr, data.window, s.x, s.y, color);
	}
}

void			draw_column(t_file data, t_bresen s)
{
	int color;

	color = 0x000066;
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
		mlx_pixel_put(data.mlx_ptr, data.window, s.x, s.y, (color += 50));
	}
}

void			ft_bresen(t_file data, t_coord *coord, int i)
{
	t_bresen s;

	if (i == 1)
		init_bresen(&s, coord);
	else
		init_bresen_down(&s, coord);
	mlx_pixel_put(data.mlx_ptr, data.window, s.x, s.y, 0xffffcc);
	if (s.dx > s.dy)
		draw_line(data, s);
	else
		draw_column(data, s);
}
