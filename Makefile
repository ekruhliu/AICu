# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/10 09:51:20 by ekruhliu          #+#    #+#              #
#    Updated: 2018/03/10 09:51:22 by ekruhliu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

C_FILES = is_smth.c read_file.c check_player_input.c make_list.c read_standart_input.c main.c \
computer_play.c helper.c play.c put_win_and_start_turn_value.c struct_tools.c

O_FILES = $(C_FILES:.c=.o)

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: lib $(NAME)

$(NAME): $(O_FILES) $(LIB)
	gcc $(FLAGS) -o $(NAME) $(O_FILES) $(LIB)

.c.o:
	gcc $(FLAGS) -c $<

lib:
	make -C libft

clean:
	make clean -C libft
	rm -rf $(O_FILES)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: clean all fclean re libft
