/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:22:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/03/10 12:22:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

t_line	*find_listend(t_line *start_line)
{
	while (start_line && start_line->next)
		start_line = start_line->next;
	return (start_line);
}

void	free_struct(t_line *begin)
{
	t_line	*tmp;

	tmp = begin;
	while (begin)
	{
		begin = begin->next;
		free(tmp);
		tmp = begin;
	}
}
