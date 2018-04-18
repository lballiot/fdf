/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:37:41 by lballiot          #+#    #+#             */
/*   Updated: 2018/04/18 18:29:52 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_file
{
	void *mlx_ptr;
	void *window;
	char **tab;
	int len;
	int height;
}					t_file;

typedef struct		s_coord
{
	int x;
	int y;
	int z;
	int x_right;
	int y_right;
	int z_right;
	int x_down;
	int y_down;
	int z_down;
	struct s_coord *next;
}					t_coord;

void	ft_check_char(char *map);

char	*ft_add_back_n(char *line);

t_coord	*ft_coord(t_file data, t_coord *coord);

t_file	ft_check_map(char *map, t_file data);

#endif
