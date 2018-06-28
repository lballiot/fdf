/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 11:42:15 by lballiot          #+#    #+#             */
/*   Updated: 2018/06/28 11:42:17 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			remove_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		ft_strdel(&tab[i++]);
	}
	free(tab);
}

void			remove_lst(t_coord *coord)
{
	t_coord *tmp;

	tmp = coord;
	while (tmp->next)
	{
		coord = tmp->next;
		free(tmp);
		tmp = coord;
	}
	free(tmp);
	tmp = NULL;
	coord = NULL;
}

void		fill_end_tab(t_file *data, int y, char **split, char **down)
{
	data->t[6] = data->i + data->space_x;
	data->t[7] = y;
	data->t[8] = ft_atoi(split[data->i]);
	if(down && down[data->i])
		down[data->i + 1] = NULL;
}