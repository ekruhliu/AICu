/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:47:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/03/10 16:47:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

char		*ft_strtrim_free(char *s)
{
	char	*res;

	res = ft_strtrim(s);
	free(s);
	s = NULL;
	return (res);
}

int			is_strnumber(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isnumber(str[i]) != 1)
			return (1);
		i++;
	}
	return (0);
}
