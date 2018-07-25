/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:37:41 by lballiot          #+#    #+#             */
/*   Updated: 2018/06/29 10:29:54 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"

typedef struct		s_coord
{
	int				point[3];
	int				right[3];
	int				down[3];
	struct s_coord	*next;
}					t_coord;

/*
**		point[0] =  x;
**		point[1] =  y;
**		point[2] =  z;
*/

typedef struct		s_file
{
	void			*mlx_ptr;
	void			*window;
	char			**tab;
	int				len_map;
	int				height_map;
	int				zoom;
	char			*av;
	t_coord			*tmp;
	int				t[9];
	int				min_x;
	int				min_y;
	int				max_x;
	int				max_y;
	int				width_win;
	int				height_win;
	int				space_x;
	int				space_y;
	int				i;
	int				evelation;
	char			**split;
	char			**down;
	int				y;
}					t_file;

typedef	struct		s_bresen
{
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
}					t_bresen;

void				ft_check_char(char *map);

char				*ft_add_back_n(char *line);

t_coord				*ft_coord(t_file *data, t_coord *coord);

t_coord				*ft_modification(t_file *data, t_coord *coord);

t_file				ft_check_map(char *map, t_file data);

void				ft_bresen(t_file data, t_coord *coord, int i);

t_file				ft_min_max(t_coord *coord, t_file *data);

void				remove_lst(t_coord *coord);

void				remove_tab(char **tab);

void				fill_end_tab(t_file *data);

void				isometrie(t_coord **e);

int					deal_key(int key, t_file *data);

#endif
