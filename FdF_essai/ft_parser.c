/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:24:46 by lballiot          #+#    #+#             */
/*   Updated: 2018/04/18 18:32:59 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

char			*ft_add_back_n(char *line)
{
	char	*tmp;
	int		i;

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

void			ft_check_char(char *map)
{
	int		i;

	i = -1;
	while (map[++i])
	{
		if ((ft_isdigit(map[i]) == 0) && map[i] != '\n' && map[i] != ' '
			&& map[i] != '-' && map[i] != '+')
		{
			ft_putstr_fd("Map invalid : presence of bad character\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}

static t_file	ft_check_before_n(char *map, t_file data)
{
	int i;

	i = -1;
	while (map[++i] != '\n')
		if ((map[i] != ' ' && map[i] != '-' && map[i] != '+') &&
			(!(map[i - 1] >= '0' && map[i - 1] <= '9')))
			data.len++;
	return (data);
}

t_file			ft_check_map(char *map, t_file data)
{
	int		i;
	int		len_line;

	i = -1;
	len_line = 0;
	data = ft_check_before_n(map, data);
	while (map[++i])
	{
		if (map[i] == '\n')
		{
			data.height++;
			if (data.len != len_line)
			{
				ft_putstr_fd("Map invalid : wrong lenght of line\n", 2);
				exit(EXIT_FAILURE);
			}
			len_line = 0;
		}
		if (map[i] != ' ' && map[i] != '\n' && map[i] != '-' && map[i] != '+')
			if (!(map[i - 1] >= '0' && map[i - 1] <= '9'))
				len_line++;
	}
	return (data);
}
