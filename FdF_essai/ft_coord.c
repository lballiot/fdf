/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:50:48 by lballiot          #+#    #+#             */
/*   Updated: 2018/04/30 13:55:17 by lballiot         ###   ########.fr       */
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
	elem->point[0] = t[0] + center; 
	elem->point[1] = t[1] + (center - 5);
	elem->point[2] = t[2];
	elem->right[0] = t[3] + center; 
	elem->right[1] = t[4] + (center - 5);
	elem->right[2] = t[5];
	elem->down[0] = t[6] + center; 
	elem->down[1] = t[7] + (center - 5);
	elem->down[2] = t[8];
	elem->next = NULL;
	if (coord == NULL)
	{
		coord = elem;
		tmp = coord;
	}
	else
    {
        while (coord->next != NULL)
        {
            coord = coord->next;
        }
		coord->next = elem;
	}
	coord = tmp;
	return (coord);
}

/*int		*ft_fill_t(int i, int j, int t[9], char **tab_split)
{
	ft_putstr("tab_split = ");
	ft_putstr(tab_split[j]);
	ft_putstr("\n");
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
	if ()
	{
		t[6] = ;
		t[7] = ;
		t[8] = ;
	}
	return (t);
}*/
 /*
void	ft_coord_next(char **tab, int i, char **down, t_coord **coord, t_file data)
{
	int j;
	int t[9];

	while(i < 9)
		t[i++] = 0;
	j = 0;
	while(tab[j] != NULL)
	{
		t[0] = i; // x
		t[1] = j; // y
		t[2] = ft_atoi(tab[j]); // z
		if (tab[j + 1] != NULL)
		{
			t[3] = i; // x_right
			t[4] = j + 1 ; // y_right
			t[5] = ft_atoi(tab[j + 1]); //z_right
		}
// find the coord of down
		if (down[j] != NULL)
		{
			t[6] = i + 1;//x_down
			t[7] = j;//y_down
			t[8] = ft_atoi(down[j]);//z_down
		}
		else 
		{
			t[6] = i;//x_down
			t[7] = j;//y_down
			t[8] = ft_atoi(tab[j]);//z_down
		}
//			*t = ft_fill_t(i, j, t, tab_split);
		*coord = ft_add_coord(coord, t, data); 
		j++;
	}
}*/

t_coord		*ft_coord(t_file data, t_coord *coord)
{
	int t[9];
	int i = 0;
	int j = 0;
	char **tab_split = NULL;
	char **tab_down = NULL;
	
	while(i < 9)
		t[i++] = 0;
	i = 0;
	while(data.tab[i] != NULL)
	{
		tab_split = ft_strsplit(data.tab[i], ' ');
		if (data.tab[i + 1] != NULL)
			tab_down = ft_strsplit(data.tab[i + 1], ' ');
//		ft_coord_next(tab_split, i, tab_down, coord, data);
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
			else 
			{
				t[6] = i;//x_down
				t[7] = j;//y_down
				t[8] = ft_atoi(tab_split[j]);//z_down
			}
//			*t = ft_fill_t(i, j, t, tab_split);
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


