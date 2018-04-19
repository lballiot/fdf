/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:50:48 by lballiot          #+#    #+#             */
/*   Updated: 2018/04/19 16:16:16 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		*ft_add_coord(t_coord *coord, int x, int y, char *z)
{
	t_coord *elem;
    static t_coord *tmp; //free tmp but when ????????

    if (!(elem=(t_coord *)malloc(sizeof(t_coord))))
        return (NULL);
    elem->x = x;
    elem->y = y;
    elem->z = ft_atoi(z);
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

t_coord		*ft_coord(t_file data, t_coord *coord)
{
	int i = 0;
	int j = 0;
	char **tab_split = NULL;

	while (data.tab[i])
	{
		tab_split = ft_strsplit(data.tab[i], ' ');
		while (tab_split[j])
		{
			coord = ft_add_coord(coord, i , j, tab_split[j]); 
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
		ft_putstr("coord->x = ");
		ft_putnbr(coord->x);
		ft_putstr("\n");
		ft_putstr("coord->y = ");
		ft_putnbr(coord->y);
		ft_putstr("\n");
		ft_putstr("coord->z = ");
		ft_putnbr(coord->z);
		ft_putstr("\n");
		coord = coord->next;
	}
*/
