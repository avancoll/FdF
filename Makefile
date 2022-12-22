# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 15:14:18 by avancoll          #+#    #+#              #
#    Updated: 2022/12/22 16:03:22 by avancoll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf.a

EXEC		= fdf

SRCS		=	SRCS/main.c\
				SRCS/key_manager.c\
				SRCS/key_manager_utils.c\
				SRCS/get_next_line.c\
				SRCS/parsing.c\
				SRCS/lst_map.c\
				SRCS/draw_map.c\
				SRCS/draw_line.c\
				SRCS/error_handler.c\
				SRCS/mlx_handler.c\
				SRCS/utils.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

.c.o:
	$(CC) $(CFLAGS) -Imlx -c -I./ $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS)
	$(CC) -lmlx -framework OpenGL -framework AppKit $(NAME) -o $(EXEC) -lm

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME) $(EXEC)

re:	fclean all

.PHONY:	all clean fclean re
