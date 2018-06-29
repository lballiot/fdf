/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 11:32:08 by lballiot          #+#    #+#             */
/*   Updated: 2018/06/29 11:32:10 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			read2(char *buf, char *cpy, char **tmp)
{
	if (ft_index(buf, C) > 0)
	{
		cpy = ft_strsub(buf, 0, ft_index(buf, C));
		*tmp = ft_strjoin_and_free(*tmp, cpy);
		ft_strdel(&cpy);
	}
}

void			return2(char **line, t_struct **l, char **cpy, t_struct *tmp_l)
{
	*line = ft_strsub((*l)->str, 1, (ft_strlen((*l)->str) - 2));
	*cpy = ft_strsub((*l)->str, 1, (ft_strlen((*l)->str) - 2));
	free((*l)->str);
	(*l)->str = ft_strdup(*cpy);
	free(*cpy);
	(*l) = tmp_l;
}

void			gnl2(char **cpy, t_struct *l)
{
	*cpy = ft_strsub(l->str, ft_r_index(l->str, C),
			(ft_strlen(l->str) - ft_r_index(l->str, C)));
	free(l->str);
	l->str = ft_strdup(*cpy);
	free(*cpy);
}
