/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:37:41 by lballiot          #+#    #+#             */
/*   Updated: 2018/05/03 13:47:58 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"

typedef struct		s_file
{
	void *mlx_ptr;
	void *window;
	char **tab;
	int len;
	int height;
	int zoom;
	char *av;
}					t_file;

typedef struct		s_coord
{
	int point[3];
				//	point[0] =  x;
				//	point[1] =  y;
				//	point[2] =  z;
	int right[3];
	int down[3];
	struct s_coord *next;
}					t_coord;

typedef	struct		s_bresen
{
//	int	xi;
//	int	yi;
//	int	xf;
//	int yf;
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;
}					t_bresen;

void	ft_check_char(char *map);

char	*ft_add_back_n(char *line);

t_coord	*ft_coord(t_file data, t_coord *coord);

void	ft_modification(t_file *data, t_coord *coord);

t_file	ft_check_map(char *map, t_file data);

void	ft_bresen(t_file data, t_coord *coord);

#endif
