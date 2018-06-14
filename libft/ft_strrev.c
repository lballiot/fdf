/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:02:48 by lballiot          #+#    #+#             */
/*   Updated: 2018/06/14 13:50:10 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*strrev;
	size_t	i;
	size_t	j;

	j = ft_strlen(str);
	i = 0;
	if (!(strrev = (char *)malloc(sizeof(char) * j + 1)))
		return (NULL);
	while (str[--j])
	{
		strrev[i] = str[j];
		i++;
	}
	strrev[i] = '\0';
	str = strrev;
	free(strrev);
	return (str);
}
