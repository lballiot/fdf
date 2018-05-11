/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:50:48 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/11 14:25:35 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_min_max(t_coord *coord, t_file *data)
{
	data->min_x = coord->point[0];
	data->min_y = coord->point[1];
	data->max_x = coord->point[0];
	data->max_y = coord->point[1];
	while (coord->next != NULL)
	{
		if (coord->point[0] < data->min_x)//x
			data->min_x = coord->point[0];
		if (coord->point[0] > data->max_x)//x
			data->max_x = coord->point[0];
		if (coord->point[1] < data->min_y)//y
			data->min_y = coord->point[1];
		if (coord->point[1] > data->max_y)//y
			data->max_y = coord->point[1];
		coord = coord->next;
	}
	coord = data->tmp;
}

t_coord		*ft_add_coord(t_coord *coord, t_file data)
{
	t_coord *e;
    static t_coord *tmp; //free tmp but when ????????

    if (!(e=(t_coord *)malloc(sizeof(t_coord))))
        return (NULL);
	e->point[0] = data.t[0] * data.zoom ; 
	e->point[1] = data.t[1] * data.zoom ; //* 150;
	e->point[2] = data.t[2] * 50;
	e->right[0] = data.t[3] * data.zoom ; //* 150; 
	e->right[1] = data.t[4] * data.zoom ; //* 150;
	e->right[2] = data.t[5] * 50;
	e->down[0] = data.t[6] * data.zoom ; //* 150; 
	e->down[1] = data.t[7] * data.zoom ; //* 150;
	e->down[2] = data.t[8] *  50;
	e->next = NULL;

/*	ft_putstr("x1 = ");
	ft_putnbr(e->point[0]);
	ft_putstr("\ny1 = ");
	ft_putnbr(e->point[1]);
	ft_putstr("\nz1 = ");
	ft_putnbr(e->point[2]);
	ft_putstr("\nx2 = ");
	ft_putnbr(e->right[0]);
	ft_putstr("\ny2 = ");
	ft_putnbr(e->right[1]);
	ft_putstr("\nz2 = ");
	ft_putnbr(e->right[2]);
	ft_putstr("\nx3 = ");
	ft_putnbr(e->down[0]);
	ft_putstr("\ny3 = ");
	ft_putnbr(e->down[1]);
	ft_putstr("\nz3 = ");
	ft_putnbr(e->down[2]);
	ft_putstr("\n");
	ft_putstr("/////////////////////// END FT_ADD_COORD\n");*/

	e->point[0] = (float)(((0.07 * (float)e->point[0] - 0.07 * (float)e->point[1])) * 3 + 200 );
	e->point[1] = (float)(((0.04 * (float)e->point[0] + 0.04 * (float)e->point[1]) - 0.2 * (float)e->point[2]) * 3 + 200 );
	e->right[0] = (float)(((0.07 * (float)e->right[0] - 0.07 * (float)e->right[1])) * 3 + 200 );
	e->right[1] = (float)(((0.04 * (float)e->right[0] + 0.04 * (float)e->right[1]) - 0.2 * (float)e->right[2]) * 3 + 200 );
	e->down[0] = (float)(((0.07 * (float)e->down[0] - 0.07 * (float)e->down[1])) * 3 + 200 );
	e->down[1] = (float)(((0.04 * (float)e->down[0] + 0.04 * (float)e->down[1]) - 0.2 * (float)e->down[2]) * 3 + 200 );
	if (coord == NULL)
	{
		coord = e;
		tmp = coord;
		data.tmp = tmp;
	}
	else
    {
        while (coord->next != NULL)
            coord = coord->next;
		coord->next = e;
	}
	coord = tmp;
	return (coord);
}

t_coord		*ft_coord(t_file data, t_coord *coord)
{
//	int t[9];
	int y = -1;
	int x = 0;
	char **tab_split = NULL;
	char **tab_down = NULL;
	
//	while(y < 9)
//		t[++y] = 0;
	y = 0;
	while(data.tab[y] != NULL)
	{
		tab_split = ft_strsplit(data.tab[y], ' ');
		if (data.tab[y + 1] != NULL)
			tab_down = ft_strsplit(data.tab[y + 1], ' ');
		while(tab_split[x] != NULL)
		{
			data.t[0] = x; // x
			data.t[1] = y; // y
			data.t[2] = ft_atoi(tab_split[x]); // z
			if (tab_split[x + 1] != NULL)
			{
				data.t[3] = x + 1; // x_right
				data.t[4] = y ; // y_right
				data.t[5] = ft_atoi(tab_split[x + 1]); //z_right
			}
// find the coord of down
			if (tab_down[x] != NULL)
			{
				data.t[6] = x;//x_down
				data.t[7] = y + 1;//y_down
				data.t[8] = ft_atoi(tab_down[x]);//z_down
			}
			else //if tab_down doesnt exist data.t[6] = -1 so error 
			{
				data.t[6] = x;//x_down
				data.t[7] = y;//y_down
				data.t[8] = ft_atoi(tab_split[x]);//z_down
				tab_down[x + 1] = NULL;
			}
//			*t = ft_fill_t(i, j, t, tab_split);
/*			int k = 0;
			while (k < 9)
			{
				ft_putstr("tab[");
				ft_putnbr(k);
				ft_putstr("] = ");
				ft_putnbr(data.t[k]);
				ft_putstr("\n\n");
				k++;
				}*/
			coord = ft_add_coord(coord, data); 
			x++;
		}
		ft_memdel((void *)tab_down);
		free(tab_split);
		x = 0;
		y++;
	}
	ft_min_max(coord, &data);
/*	if (data.max_x > 2560 || data.max_y > 1390)
	{
		ft_putstr("toto\n");
		data.zoom--;
		return (ft_coord(data, coord));
		}*/
	printf("min_x = %d\tmin_y = %d\nmax_x = %d\tmax_y = %d\n", data.min_x, data.min_y, data.max_x, data.max_y);
	return (coord);
}


/////////////////////////////////////
//       TO PRINT THE LIST         //
/////////////////////////////////////

/*

    ft_putstr("down[0] = ");
    ft_putnbr(coord->down[0]);
    ft_putstr("\npoindata.t[0] = ");
    ft_putnbr(coord->poindata.t[0]);
	ft_putstr("\n");


	while (coord->next != NULL)
	{
		ft_putstr("x = ");
		ft_putnbr(coord->poindata.t[0]);
		ft_putstr("\ny = ");
		ft_putnbr(coord->poindata.t[1]);
		ft_putstr("\nz = ");
		ft_putnbr(coord->poindata.t[2]);
		ft_putstr("\nx = ");
		ft_putnbr(coord->righdata.t[0]);
		ft_putstr("\ny = ");
		ft_putnbr(coord->righdata.t[1]);
		ft_putstr("\nz = ");
		ft_putnbr(coord->righdata.t[2]);
		ft_putstr("\nx = ");
		ft_putnbr(coord->down[0]);
		ft_putstr("\ny = ");
		ft_putnbr(coord->down[1]);
		ft_putstr("\nz = ");
		ft_putnbr(coord->down[2]);
		ft_putstr("\n");
		ft_putstr("endendnednedend\n");
		coord = coord->next;
	}
	coord = tmp;


	while (coord->next != NULL)
	{
		ft_putstr("x = ");
		ft_putnbr(coord->poindata.t[0]);
		ft_putstr("\ny = ");
		ft_putnbr(coord->poindata.t[1]);
		ft_putstr("\nz = ");
		ft_putnbr(coord->poindata.t[2]);
		ft_putstr("\n");
		coord = coord->next;
	}

*/


