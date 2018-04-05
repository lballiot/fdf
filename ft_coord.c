/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:02:34 by lballiot          #+#    #+#             */
/*   Updated: 2018/04/05 16:51:22 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		*ft_find_z(char **tab, t_coord *coord)
{
	t_coord *tmp_link;
	char **tab_split;
	tmp_link = coord;
	int i = 0;
	int j = 0;

	while (tab[i])
	{
		ft_putstr("tab[i] =");
		ft_putstr(tab[i]);
		ft_putstr("= \n");
		tab_split = ft_strsplit(tab[i], ' ');
		while (tab_split[j])
		{
			coord->z = ft_atoi(tab_split[j]);
			ft_putstr("coord->z = ");
			ft_putnbr(coord->z);
			ft_putstr("\n");
			coord = coord->next;
			ft_putstr("coord->x = ");
			ft_putnbr(coord->x);
			ft_putstr("\n");




			ft_putstr("tab[");
			ft_putnbr(j);
			ft_putstr("] = ");
			ft_putstr(tab_split[j]);
			ft_putchar('\n');
			ft_putstr("coord->z = ");
			ft_putnbr(coord->z);
			ft_putstr("\n");
			j++;
			coord = coord->next;
		}
		j = 0;
		i++;
	}
	coord = tmp_link;
	return (coord);
}

t_coord		*ft_coord(char **tab, t_coord *coord)
{
	int i = 0;
	int j = 0;
	t_coord *tmp_link;
	int place = 0;
	char **tab_split;

	if (tab)
		if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
			return (NULL);
	while (tab[i])
	{
//		ft_putstr("\n");//
//		ft_putstr("tab[");//
//      ft_putnbr(i);//
//      ft_putstr("] =");//
//      ft_putstr(tab[i]);//
//       ft_putstr("=\n");//
		while (tab[i][j])
		{
//			ft_putstr("tab[");//
//			ft_putnbr(i);//
//			ft_putstr("][");//
//			ft_putnbr(j);//
//			ft_putstr("] = ");//
//			ft_putchar(tab[i][j]);//
//			ft_putchar('\n');//
			if (j != 0)
				if ((tab[i][j] >= '0' && tab[i][j] <= '9') && !(tab[i][j - 1] >= '0' && tab[i][j - 1] <= '9'))
						place++;
			if (tab[i][j] >= '0' && tab[i][j] <= '9')
			{
				if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
					return (NULL);
// X	OK
				coord->x = i;
//				ft_putstr("coord->x = ");
//				ft_putnbr(coord->x);
//				ft_putstr("\n");
// Y	OK 
				if (!(tab[i][j - 1] >= '0' && tab[i][j - 1] <= '9'))
				{
					coord->y = place;
//					ft_putstr("coord->y = ");
//					ft_putnbr(coord->y);
//					ft_putstr("\n");
				}
// Z		atoi du ou des chiffres + split space 
				if (i == 0 && place == 0)
					tmp_link = coord;
			}
			j++;
		}
		j = 0;
		place = 0;
		coord = coord->next;
		i++;
	}
	i = 0;
	j = 0;
	coord = tmp_link;
	while (tab[i])
	{
		ft_putstr("tab[i] =");
		ft_putstr(tab[i]);
		ft_putstr("= \n");
		tab_split = ft_strsplit(tab[i], ' ');
		while (tab_split[j])
		{
			coord->z = ft_atoi(tab_split[j]);
			ft_putstr("tab[");
			ft_putnbr(j);
			ft_putstr("] = ");
			ft_putstr(tab_split[j]);
			ft_putchar('\n');
			ft_putstr("coord->z = ");
			ft_putnbr(coord->z);
			ft_putstr("\n");
			if (coord->next == NULL)
			{
				ft_putstr("NULL\n");
			}
			coord = coord->next;
			j++;
		}
		j = 0;
		i++;
	}
	coord = tmp_link;
	ft_putstr("ENENENENENENEND\n");
//	coord = ft_find_z(tab, coord);
//	ft_putstr("coord->z = ");
//	ft_putnbr(coord->z);
//	ft_putstr("\n");

	return (coord);
}
