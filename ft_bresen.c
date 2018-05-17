/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 13:55:42 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/17 12:36:03 by lballiot         ###   ########.fr       */
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


void    ft_test(t_coord *coord, t_file data, int i)
{
    t_bresen s;
    long long color;

    color = 0xFFFFFFF;
	if (i == 1)
		init_bresen(&s, coord);
	else
		init_bresen_down(&s, coord);
    mlx_pixel_put(data.mlx_ptr, data.window, (s.x), (s.y), color);

//	printf("x = %d\t y = %d\t z = %d\nx2 = %d\t x2 = %d\t z2 = %d\nx3 = %d\t y3 = %d\t z3 = %d\n\n", coord->point[0], coord->point[1], coord->point[2], coord->right[0], coord->right[1], coord->right[2], coord->down[0], coord->down[1], coord->down[2]);
	
    if (s.dx > s.dy) //vertical rouge
    {
        s.cumul = s.dx / 2;
        s.i = 0;
//      color = color * 500;
        while (++s.i <= s.dx)
        {
            s.x += s.xinc;
            s.cumul += s.dy;
            if (s.cumul >= s.dx)
            {
                s.cumul -= s.dx;
                s.y += s.yinc;
            }

            mlx_pixel_put(data.mlx_ptr, data.window, (s.x), (s.y), color);
        }
    }
    else //horizontal blanc
    {
		s.cumul = s.dy / 2;
        s.i = 0;
        while (++s.i <= s.dy)
        {
//                      if ( coord->down[2] > 0 ||  coord->right[2] > 0)
//              color = 0xFE0000;

//				color = 0xFE0000;
			s.y += s.yinc;
            s.cumul += s.dx;
            if (s.cumul >= s.dy)
            {
                s.cumul -= s.dy;
                s.x += s.xinc;
            }
            mlx_pixel_put(data.mlx_ptr, data.window, (s.x), (s.y), (color+=500 ));
        }
    }
}

void    ft_bresen(t_file data, t_coord *coord)
{
    t_coord *tmp;

    tmp = coord;
    if (coord->next)
    {
        tmp = coord->next;
        ft_test(coord, data, 1); //traint horizontal (point, right)
        ft_test(coord, data, 0); // trait vertical (point, down)
    }
    coord = tmp;
}
