/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_for_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:16:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/03/10 12:16:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	put_valuewin_to_struct(t_line *start_line)
{
	t_line	*end_line;

	end_line = find_listend(start_line);
	while (end_line)
	{
		find_win_value(end_line);
		end_line = end_line->prev;
	}
}

void	find_win_value(t_line *line)
{
	if (line->next == NULL)
	{
		line->win = 1;
		if (line->matches == 1 || (line->matches % 4 == 1 && line->matches > 4))
			line->start_turn = 2;
		else
			line->start_turn = 1;
	}
	else
		put_value_start_turn(line);
}

void	put_value_start_turn(t_line *line)
{
	int		start_turn_next_line;
	t_line	*next_line;

	next_line = line->next;
	start_turn_next_line = next_line->start_turn;
	if (start_turn_next_line == 1)
	{
		line->win = 1;
		if (line->matches % 4 == 1 && line->matches > 4)
			line->start_turn = 2;
		else if (line->matches < 4)
			line->start_turn = 1;
		else
			line->start_turn = 1;
	}
	else
	{
		line->win = 0;
		if (line->matches == 1 || (line->matches % 4 == 1 && line->matches > 4))
			line->start_turn = 1;
		else if (line->matches < 4)
			line->start_turn = 1;
		else
			line->start_turn = 2;
	}
}
