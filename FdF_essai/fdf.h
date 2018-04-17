/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:37:41 by lballiot          #+#    #+#             */
/*   Updated: 2018/04/05 16:57:26 by lballiot         ###   ########.fr       */
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
}					t_file;

typedef struct		s_coord
{
	int x;
	int y;
	int z;
	struct s_coord *next;
}					t_coord;

void	ft_check_char(char *map);

char	*ft_add_back_n(char *line);

t_coord	*ft_coord(char **tab, t_coord *coord);

void	ft_check_map(char *map);

#endif
