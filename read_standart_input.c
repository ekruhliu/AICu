/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_standart_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:26:07 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/10 15:26:08 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static	int	part_1(int mat, char *tmp)
{
	if (ft_istrue(mat) != 1)
	{
		free(tmp);
		return (1);
	}
	return (0);
}

int			read_standart_input(t_line **begin, int fd)
{
	char	*tmp;
	int		mat;
	int		i;

	while (get_next_line(fd, &tmp) >= 0)
	{
		i = 0;
		tmp = ft_strtrim_free(tmp);
		if (*tmp == 0)
		{
			free(tmp);
			return (0);
		}
		if (is_strnumber(tmp) == 1)
			return (1);
		mat = ft_atoi(tmp);
		if (part_1(mat, tmp) == 1)
			return (1);
		make_list(mat, begin);
		free(tmp);
	}
	close(fd);
	return (0);
}
