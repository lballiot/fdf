#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lballiot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/30 11:48:51 by lballiot          #+#    #+#              #
#    Updated: 2018/05/17 14:13:55 by lballiot         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = main.c ft_parser.c ft_coord.c ft_modif.c ft_bresen.c min_max.c

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror 

FLAGS = -lmlx -framework OpenGL -framework AppKit -L/usr/local/lib/ \
		-I/usr/local/include libft/libft.a

HPATH = -I .

RM = rm -rf 

%.c.o : 
	@$(CC) -c $(CFLAGS) $(SRC) $(HPATH)

$(NAME) : $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(HPATH) $(FLAGS)

clean :
	@$(RM) $(OBJ)
	@make clean -C libft

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C libft

re : fclean all

all : $(NAME)