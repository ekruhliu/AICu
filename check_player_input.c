/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:25:47 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/10 15:25:48 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static	void	part_1(char *tmp)
{
	ft_printf("\033[31mERROR: Use numbers!\n\e[m");
	ft_printf("\e[0;34mEnter a number of matches: ");
	free(tmp);
}

static	void	part_2(char *tmp)
{
	ft_printf("\033[31mERROR: Bad number of matches!\n\e[m");
	ft_printf("\e[0;34mEnter a number of matches: \e[m");
	free(tmp);
}

int				check_player_input(t_map *map)
{
	char	*tmp;
	int		mat;

	ft_printf("\e[0;34mEnter a number of matches: \e[m");
	while (get_next_line(STANDART_INPUT, &tmp) >= 0)
	{
		tmp = ft_strtrim_free(tmp);
		if (is_strnumber(tmp) == 1)
		{
			part_1(tmp);
			continue;
		}
		mat = ft_atoi(tmp);
		if (ft_ismat(mat, map) != 1)
		{
			part_2(tmp);
			continue;
		}
		else
		{
			free(tmp);
			break ;
		}
	}
	return (mat);
}
