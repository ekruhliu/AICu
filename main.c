/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 09:33:49 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/10 09:33:53 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	part_1(t_line **begin)
{
	int		fd;

	fd = 0;
	if (read_standart_input(begin, fd) == 1)
	{
		ft_printf("\033[31mERROR!\n\e[m");
		return (1);
	}
	return (0);
}

static int	part_2(t_line **begin, char *argv)
{
	if (read_file(begin, argv) == 1)
	{
		ft_printf("\033[31mERROR!\n\e[m");
		return (1);
	}
	return (0);
}

static int	check_count_argument(int argc, char **argv, t_line **begin)
{
	if (argc == 1)
		if (part_1(begin) == 1)
		{
			free_struct(*begin);
			return (-1);
		}
	if (argc == 2)
		if (part_2(begin, argv[1]) == 1)
		{
			free_struct(*begin);
			return (-1);
		}
	if (argc > 2)
	{
		ft_printf("\033[31mERROR: Too many arguments!\n\e[m");
		free_struct(*begin);
		return (-1);
	}
	if (*begin == NULL)
	{
		ft_printf("\033[31mERROR!\n\e[m");
		return (-1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_line	*begin;
	t_map	*map;

	begin = NULL;
	if (check_count_argument(argc, argv, &begin) == -1)
		return (-1);
	put_valuewin_to_struct(begin);
	map = create_map(begin);
	play(map);
	free(map);
	return (0);
}
