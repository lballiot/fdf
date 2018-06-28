/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:49:21 by lballiot          #+#    #+#             */
/*   Updated: 2018/06/21 11:56:39 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char		*dest;

	dest = NULL;
	if (s1 && s2)
	{
		if (!(dest = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		dest = ft_strcpy(dest, s1);
		dest = ft_strcat(dest, s2);
		free(s1);
		ft_strclr(s2);
		return (dest);
	}
	ft_strdel(&dest);
	return (NULL);
}
