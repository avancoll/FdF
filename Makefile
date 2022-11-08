# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 15:14:18 by avancoll          #+#    #+#              #
#    Updated: 2022/11/08 12:37:12 by avancoll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf.a

EXEC		= fdf

SRCS		= SRCS/main.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

.c.o:
	$(CC) $(CFLAGS) -Imlx -c -I./ $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS)
	$(CC) -lmlx -framework OpenGL -framework AppKit $(NAME) -o $(EXEC)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME) $(EXEC)

re:	fclean all

.PHONY:	all clean fclean re
