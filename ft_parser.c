/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:24:46 by lballiot          #+#    #+#             */
/*   Updated: 2018/04/03 15:52:11 by karakhirn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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

/*
  static int c;
  static int n;
  
  n = 0;
  c = 0;
*/

void	ft_check_map(char *map)
{
	int i;
	int len_line;
	int len_save;
	
	i = -1;
	len_line = 0;
	len_save = 0;
	while (map[++i] != '\n')
	{
		if (map[i] != ' ' && map[i] != '-' && map[i] != '+')
			if (! (map[i - 1] >= '0' && map[i - 1] <= '9'))
				len_save++;
	}
	i = -1;
	while (map[++i])
	{
		if (map[i] == '\n')
		{
			if (len_save != len_line)
			{
				ft_putstr_fd("Map invalid : wrong lenght of line\n", 2);
				exit(EXIT_FAILURE);
			}
			len_line = 0;
		}
		if (map[i] != ' ' && map[i] != '\n' && map[i] != '-' && map[i] != '+')
		{
			if (! (map[i - 1] >= '0' && map[i - 1] <= '9'))
				len_line++;
		}
	}
	
	ft_putstr("check_map\n");
	
	
}
