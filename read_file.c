/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:26:19 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/10 15:26:20 by ekruhliu         ###   ########.fr       */
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

int			read_file(t_line **begin, char *argv)
{
	char	*tmp;
	int		mat;
	int		fd;
	int		i;
	int		read_res;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (1);
	while ((read_res = get_next_line(fd, &tmp)) != 0)
	{
		i = 0;
		if (read_res == -1)
			return (1);
		tmp = ft_strtrim_free(tmp);
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
