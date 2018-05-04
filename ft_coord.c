/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:50:48 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/04 16:06:43 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		*ft_add_coord(t_coord *coord, int t[9], t_file data)
{
	t_coord *elem;
	int center;
    static t_coord *tmp; //free tmp but when ????????

    if (!(elem=(t_coord *)malloc(sizeof(t_coord))))
        return (NULL);
	center = data.zoom / 2;
	elem->point[0] = (t[0] + center) * data.zoom; 
	elem->point[1] = (t[1] + (center - 5)) * data.zoom;
	elem->point[2] = t[2];
	elem->right[0] = (t[3] + center) * data.zoom; 
	elem->right[1] = (t[4] + (center - 5)) * data.zoom;			//GOOD ELEM
	elem->right[2] = t[5];
	elem->down[0] = (t[6] + center) * data.zoom; 
	elem->down[1] = (t[7] + (center - 5)) * data.zoom;
	elem->down[2] = t[8];
	elem->next = NULL;

	ft_putstr("x = ");
	ft_putnbr(elem->point[0]);
	ft_putstr("\ny = ");
	ft_putnbr(elem->point[1]);
	ft_putstr("\nz = ");
	ft_putnbr(elem->point[2]);
	ft_putstr("\nx = ");
	ft_putnbr(elem->right[0]);
	ft_putstr("\ny = ");
	ft_putnbr(elem->right[1]);
	ft_putstr("\nz = ");
	ft_putnbr(elem->right[2]);
	ft_putstr("\nx = ");
	ft_putnbr(elem->down[0]);
	ft_putstr("\ny = ");
	ft_putnbr(elem->down[1]);
	ft_putstr("\nz = ");
	ft_putnbr(elem->down[2]);
	ft_putstr("\n");
	ft_putstr("ELELELELELELELELELELE\n");


//	elem->point[0] = (elem->point[1] / data.height) + (elem->point[0] / data.len);
//	elem->point[1] = (elem->point[1] / data.height) - (elem->point[0] / data.len);
//	elem->right[0] = (elem->right[1] / data.height) + (elem->right[0] / data.len);
//	elem->right[1] = (elem->right[1] / data.height) - (elem->right[0] / data.len);
//	elem->down[0] = (elem->down[1] / data.height) + (elem->down[0] / data.len);
//	elem->down[1] = (elem->down[1] / data.height) - (elem->down[0] / data.len);

	elem->point[1] = (int)((0.6 * (float)elem->point[0] - 0.8 * (float)elem->point[1]) * data.zoom);
	elem->point[0] = (int)(((float)elem->point[2] + 0.6 / 2 * (float)elem->point[0] - 0.8 / 2 * (float)elem->point[1]) * data.zoom);
	elem->right[1] = (int)((0.6 * (float)elem->right[0] - 0.8 * (float)elem->right[1]) * data.zoom);
	elem->right[0] = (int)(((float)elem->right[2] + 0.6 / 2 * (float)elem->right[0] - 0.8 / 2 * (float)elem->right[1]) * data.zoom);
	elem->down[1] = (int)((0.6 * (float)elem->down[0] - 0.8 * (float)elem->down[1]) * data.zoom);
	elem->down[0] = (int)(((float)elem->down[2] + 0.6 / 2 * (float)elem->down[0] - 0.8 / 2 * (float)elem->down[1]) * data.zoom);


	if (coord == NULL)
	{
		coord = elem;
		tmp = coord;
	}
	else
    {
        while (coord->next != NULL)
            coord = coord->next;
		coord->next = elem;
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
	coord = tmp;
	return (coord);
}

t_coord		*ft_coord(t_file data, t_coord *coord)
{
	int t[9];
	int i = -1;
	int j = 0;
	char **tab_split = NULL;
	char **tab_down = NULL;
	
	while(i < 9)
		t[++i] = 0;
	i = 0;
	while(data.tab[i] != NULL)
	{
		tab_split = ft_strsplit(data.tab[i], ' ');
		if (data.tab[i + 1] != NULL)
			tab_down = ft_strsplit(data.tab[i + 1], ' ');
		while(tab_split[j] != NULL)
		{
			t[0] = i; // x
			t[1] = j; // y
			t[2] = ft_atoi(tab_split[j]); // z
			if (tab_split[j + 1] != NULL)
			{
				t[3] = i; // x_right
				t[4] = j + 1 ; // y_right
				t[5] = ft_atoi(tab_split[j + 1]); //z_right
			}
// find the coord of down
			if (tab_down[j] != NULL)
			{
				t[6] = i + 1;//x_down
				t[7] = j;//y_down
				t[8] = ft_atoi(tab_down[j]);//z_down
			}
			else //if tab_down doesnt exist t[6] = -1 so error 
			{
				t[6] = i;//x_down
				t[7] = j;//y_down
				t[8] = ft_atoi(tab_split[j]);//z_down
				tab_down[j + 1] = NULL;
			}
//			*t = ft_fill_t(i, j, t, tab_split);
			int k = 0;
			while (k < 9)
			{
				ft_putstr("tab[");
				ft_putnbr(k);
				ft_putstr("] = ");
				ft_putnbr(t[k]);
				ft_putstr("\n");
				k++;
			}
			coord = ft_add_coord(coord, t, data); 
			j++;
		}
		ft_memdel((void *)tab_down);
		free(tab_split);
		j = 0;
		i++;
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


