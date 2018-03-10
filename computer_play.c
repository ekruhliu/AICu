/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computer_play.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 13:43:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/03/10 13:43:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		computer_play(t_map *map)
{
	int		nb_mutch;

	if (map->line->win)
		nb_mutch = win(map->line);
	else
		nb_mutch = lose(map->line);
	return (nb_mutch);
}

int		win(t_line *line)
{
	int		mutch;

	mutch = (line->matches - 1) % 4;
	if (mutch == 0)
		mutch = 1;
	return (mutch);
}

int		lose(t_line *line)
{
	int		mutch;

	mutch = line->matches % 4;
	if (mutch == 0)
		mutch = 1;
	return (mutch);
}
