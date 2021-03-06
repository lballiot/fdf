/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:11:45 by lballiot          #+#    #+#             */
/*   Updated: 2018/06/29 11:20:37 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_check_end(char **line, t_struct *l, char *tmp)
{
	if ((l->i == 0 && tmp[0] == '\0') || l->i == -1)
	{
		free(l->str);
		free(tmp);
		return (l->i);
	}
	if (tmp)
	{
		free(l->str);
		*line = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	free(l->str);
	free(tmp);
	return (0);
}

int				ft_read(t_struct **l, char **tmp, char **line, t_struct *tmp_l)
{
	char *buf;
	char *cpy;

	cpy = NULL;
	buf = ft_strnew(BUFF_SIZE);
	while (((*l)->i = read((*l)->fd, buf, BUFF_SIZE)) != EOF && (*l)->i > 0)
	{
		if (ft_strchr(buf, C))
		{
			read2(buf, cpy, tmp);
			if (ft_strstr(buf, CH) && (*line = ft_strdup(*tmp)))
			{
				free((*l)->str);
				(*l)->str = ft_strdup(ft_strstr(buf, CH));
			}
			ft_strdel(tmp);
			ft_strdel(&buf);
			if (tmp_l)
				(*l) = tmp_l;
			return (1);
		}
		*tmp = ft_strjoin_and_free(*tmp, buf);
	}
	free(buf);
	return (ft_check_end(line, (*l), *tmp));
}

int				ft_return(char **line, t_struct **l, t_struct *tmp_l, int flag)
{
	char *tmp;
	char *cpy;

	tmp = ft_strnew(1);
	if (flag == 1)
		return2(line, l, &cpy, tmp_l);
	else
	{
		if (ft_index((*l)->str, C) > 0)
		{
			free(tmp);
			tmp = ft_strsub((*l)->str, 0, ft_index((*l)->str, C));
		}
		*line = ft_strdup(tmp);
		if (ft_strstr((*l)->str, CH))
		{
			cpy = ft_strdup(ft_strstr((*l)->str, CH));
			free((*l)->str);
			(*l)->str = ft_strdup(cpy);
			free(cpy);
		}
		*l = tmp_l;
	}
	free(tmp);
	return (1);
}

static t_struct	*ft_struct(const int fd, t_struct **list_static)
{
	t_struct *new;

	if (*list_static)
		while ((*list_static)->fd != fd && (*list_static)->next != NULL)
			list_static = &(*list_static)->next;
	else
	{
		if (!(new = (t_struct *)malloc(sizeof(t_struct))))
			return (NULL);
		new->fd = fd;
		new->str = NULL;
		new->next = NULL;
		*list_static = new;
	}
	if (((*list_static)->next == NULL && (*list_static)->fd != fd))
	{
		if (!(new = (t_struct *)malloc(sizeof(t_struct))))
			return (NULL);
		new->fd = fd;
		new->str = NULL;
		new->next = NULL;
		(*list_static)->next = new;
		list_static = &(*list_static)->next;
	}
	return (*list_static);
}

int				get_next_line(const int fd, char **line)
{
	char			*tmp;
	static t_struct	*l;
	t_struct		*tmp_link;
	char			*cpy;

	tmp = ft_strnew(1);
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	tmp_link = l;
	l = ft_struct(fd, &l);
	if (l->str)
	{
		if ((l->str[0] == C && l->str[1] == C && l->str[2] == '\0'))
			return (ft_return(line, &l, tmp_link, 1));
		if (ft_r_index(l->str, C) > 0)
		{
			gnl2(&cpy, l);
		}
		if (ft_strchr(l->str, C))
			return (ft_return(line, &l, tmp_link, 0));
		free(tmp);
		tmp = ft_strdup(l->str);
		ft_strdel(&l->str);
	}
	return (ft_read(&l, &tmp, line, tmp_link));
}
