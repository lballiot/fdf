/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:50:48 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/11 10:57:38 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		*ft_add_coord(t_coord *coord, int t[9], t_file data)
{
	t_coord *e;
	int center;
    static t_coord *tmp; //free tmp but when ????????

    if (!(e=(t_coord *)malloc(sizeof(t_coord))))
        return (NULL);
	center = data.zoom / 2;
	e->point[0] = (t[0] + center) * data.zoom; 
	e->point[1] = (t[1] + center) * data.zoom; //* 150;
	e->point[2] = t[2] * 50;
	e->right[0] = (t[3] + center) * data.zoom; //* 150; 
	e->right[1] = (t[4] + center) * data.zoom; //* 150;
	e->right[2] = t[5] * 50;
	e->down[0] = (t[6] + center) * data.zoom; //* 150; 
	e->down[1] = (t[7] + center) * data.zoom; //* 150;
	e->down[2] = t[8] *  50;
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
	int t[9];
	int y = -1;
	int x = 0;
	char **tab_split = NULL;
	char **tab_down = NULL;
	
	while(y < 9)
		t[++y] = 0;
	y = 0;
	while(data.tab[y] != NULL)
	{
		printf("tab =%s=\ni (y) = %d\n", data.tab[y], y);
		tab_split = ft_strsplit(data.tab[y], ' ');
		if (data.tab[y + 1] != NULL)
			tab_down = ft_strsplit(data.tab[y + 1], ' ');
		while(tab_split[x] != NULL)
		{
			t[0] = x; // x
			t[1] = y; // y
			t[2] = ft_atoi(tab_split[x]); // z
			if (tab_split[x + 1] != NULL)
			{
				t[3] = x + 1; // x_right
				t[4] = y ; // y_right
				t[5] = ft_atoi(tab_split[x + 1]); //z_right
			}
// find the coord of down
			if (tab_down[x] != NULL)
			{
				t[6] = x;//x_down
				t[7] = y + 1;//y_down
				t[8] = ft_atoi(tab_down[x]);//z_down
			}
			else //if tab_down doesnt exist t[6] = -1 so error 
			{
				t[6] = x;//x_down
				t[7] = y;//y_down
				t[8] = ft_atoi(tab_split[x]);//z_down
				tab_down[x + 1] = NULL;
			}
//			*t = ft_fill_t(i, j, t, tab_split);
/*			int k = 0;
			while (k < 9)
			{
				ft_putstr("tab[");
				ft_putnbr(k);
				ft_putstr("] = ");
				ft_putnbr(t[k]);
				ft_putstr("\n\n");
				k++;
				}*/
			coord = ft_add_coord(coord, t, data); 
			x++;
		}
		ft_memdel((void *)tab_down);
		free(tab_split);
		x = 0;
		y++;
	}
	return (coord);
}


/////////////////////////////////////
//       TO PRINT THE LIST         //
/////////////////////////////////////

/*

    ft_putstr("down[0] = ");
    ft_putnbr(coord->down[0]);
    ft_putstr("\npoint[0] = ");
    ft_putnbr(coord->point[0]);
	ft_putstr("\n");


	while (coord->next != NULL)
	{
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
		coord = coord->next;
	}
	coord = tmp;


	while (coord->next != NULL)
	{
		ft_putstr("x = ");
		ft_putnbr(coord->point[0]);
		ft_putstr("\ny = ");
		ft_putnbr(coord->point[1]);
		ft_putstr("\nz = ");
		ft_putnbr(coord->point[2]);
		ft_putstr("\n");
		coord = coord->next;
	}

*/


