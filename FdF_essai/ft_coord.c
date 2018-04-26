/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:50:48 by lballiot          #+#    #+#             */
/*   Updated: 2018/04/26 12:10:39 by lballiot         ###   ########.fr       */
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
	elem->point[1] = t[1] + center - 5;
	elem->point[2] = t[2];
	elem->right[0] = t[3] + center; 
	elem->right[1] = t[4] + center - 5;
	elem->right[2] = t[5];
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

t_coord		*ft_coord(t_file data, t_coord *coord)
{
	int t[9];
	int i = 0;
	int j = 0;
	char **tab_split = NULL;
	
	while(i < 9)
		t[i++] = 0;
	i = 0;
	while(data.tab[i])
	{
		tab_split = ft_strsplit(data.tab[i], ' ');
		while(tab_split[j])
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
/*				if ()
				{
					t[6] = ;
					t[7] = ;
					t[8] = ;
				}
*/

//			*t = ft_fill_t(i, j, t, tab_split);
			coord = ft_add_coord(coord, t, data); 
			j++;
		}
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
		ft_putstr("\n");
		coord = coord->next;
	}
*/
