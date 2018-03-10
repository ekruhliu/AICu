/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 13:22:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/03/10 13:22:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

t_map	*create_map(t_line *line)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	new->line = line;
	if (line->start_turn == COMPUTER)
		new->turn = COMPUTER;
	else
		new->turn = PLAYER;
	return (new);
}

void	play(t_map *map)
{
	int		del_match;

	print_matches(map->line);
	while (map->line != NULL)
	{
		if (map->turn == COMPUTER)
			del_match = computer_play(map);
		else
			del_match = check_player_input(map);
		print_map(map, del_match);
	}
	if (map->turn == COMPUTER)
		ft_printf("\e[1;33mComputer win !!!\n\e[m");
	else
		ft_printf("\e[1;33mPlayer win !!!\n\e[m");
}

void	print_map(t_map *map, int del_match)
{
	if (map->turn == COMPUTER)
	{
		ft_printf("\e[1;34mComputer take %d matches\n\n\e[m", del_match);
		map->turn = PLAYER;
	}
	else
	{
		ft_printf("\e[0;35mPlayer take %d matches\n\n\e[m", del_match);
		map->turn = COMPUTER;
	}
	delete_mathes(map, del_match);
	print_matches(map->line);
}

void	delete_mathes(t_map *map, int del_match)
{
	t_line	*tmp;

	map->line->matches -= del_match;
	if (map->line->matches == 0)
	{
		tmp = map->line;
		map->line = map->line->next;
		free(tmp);
	}
}

void	print_matches(t_line *line)
{
	int i;

	while (line)
	{
		i = 0;
		while (i < line->matches)
		{
			ft_printf("\e[1;33m|\e[m");
			i++;
		}
		ft_printf("\n");
		line = line->next;
	}
	ft_printf("\n");
}
