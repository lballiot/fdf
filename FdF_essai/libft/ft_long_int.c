/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:49:50 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/11 13:52:53 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_long_int(int n)
{
	int		ret;

	ret = 1;
	if (n < 0)
	{
		ret++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		ret++;
	}
	return (ret);
}
