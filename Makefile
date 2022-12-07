# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 15:14:18 by avancoll          #+#    #+#              #
#    Updated: 2022/12/07 15:10:19 by avancoll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf.a

EXEC		= fdf

SRCS		=	SRCS/main.c\
				SRCS/key_manager.c\
				SRCS/key_manager_utils.c\
				SRCS/get_next_line.c\
				SRCS/get_next_line_utils.c\
				SRCS/parsing.c\
				SRCS/lst_map.c\
				SRCS/drawmap.c\

OBJS		= $(SRCS:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -O3 -O2 -Os

RM			= rm -f

.c.o:
	$(CC) $(CFLAGS) -Imlx -c -I./ $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS)
	$(CC) -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g $(NAME) -o $(EXEC) -lm

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME) $(EXEC)

re:	fclean all

.PHONY:	all clean fclean re
