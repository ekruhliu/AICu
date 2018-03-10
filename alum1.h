/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 09:50:25 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/03/10 09:50:27 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include "./libft/includes/libft.h"
# include <fcntl.h>

# define PLAYER 0
# define COMPUTER 1
# define STANDART_INPUT 0

typedef	struct		s_line
{
	int				win;
	int				start_turn;
	int				matches;
	struct s_line	*next;
	struct s_line	*prev;
}					t_line;

typedef struct		s_map
{
	int				turn;
	t_line			*line;
}					t_map;

/*
**	line_for_win.c
*/

void				put_valuewin_to_struct(t_line *start_line);
void				find_win_value(t_line *line);
void				put_value_start_turn(t_line *line);

/*
**	struct_tools.c
*/

t_line				*find_listend(t_line *start_line);
void				free_struct(t_line *begin);

/*
**	play.c
*/

t_map				*create_map(t_line *line);
void				play(t_map *map);
void				print_map(t_map *map, int del_match);
void				delete_mathes(t_map *map, int del_match);
void				print_matches(t_line *line);

/*
**	computer_play.c
*/

int					computer_play(t_map *map);
int					win(t_line *line);
int					lose(t_line *line);

/*
**	helper.c
*/

char				*ft_strtrim_free(char *s);
int					is_strnumber(char *str);

int					check_player_input(t_map *map);
int					ft_istrue(int i);
int					ft_isnumber(char c);
int					ft_ismat(int mat, t_map *map);
void				make_list(int mat, t_line **begin);
int					read_file(t_line **begin, char *argv);
int					read_standart_input(t_line **begin, int fd);

#endif
