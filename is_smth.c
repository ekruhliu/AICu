/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_smth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:28:55 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/10 15:28:55 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		ft_istrue(int i)
{
	if (i >= 1 && i <= 10000)
		return (1);
	return (0);
}

int		ft_isnumber(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_ismat(int mat, t_map *map)
{
	if ((mat >= 1 && mat <= 3) && (mat <= map->line->matches))
		return (1);
	return (0);
}
