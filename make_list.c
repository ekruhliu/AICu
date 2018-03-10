/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:29:33 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/10 15:29:33 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	make_list(int mat, t_line **begin)
{
	t_line	*new;
	t_line	*end;

	end = find_listend(*begin);
	new = malloc(sizeof(t_line));
	new->matches = mat;
	new->next = NULL;
	new->prev = end;
	if (*begin == NULL)
		*begin = new;
	else
		end->next = new;
}
