/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:24:46 by lballiot          #+#    #+#             */
/*   Updated: 2018/03/30 15:51:40 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_add_back_n(char *line)
{
	char *tmp;
	int i;

	i = 0;
	tmp = ft_strnew(ft_strlen(line) + 1);
	while (line[i])
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = '\n';
	ft_strdel(&line);
	return (tmp);
}

void	ft_parser(char *map) //if failed exit failure
{
	int i;

	i = -1;
	ft_putstr("map =");
	ft_putstr(map);
	ft_putstr("= map\n");
	while (map[++i])
	{
//		if(map[i] != '-' && map[i] != '+' && (map[i] < 48 && map[i] > 57))
//			return (-1);
	}
}
