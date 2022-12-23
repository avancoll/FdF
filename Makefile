# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 15:14:18 by avancoll          #+#    #+#              #
#    Updated: 2022/12/23 17:10:19 by avancoll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf.a

NAME_BONUS	= fdf_bonus.a

EXEC		= fdf

EXEC_BONUS	= fdf_bonus

SRCS		=	mandatory/srcs/main.c\
				mandatory/srcs/key_manager.c\
				mandatory/srcs/key_manager_utils.c\
				mandatory/srcs/get_next_line.c\
				mandatory/srcs/parsing.c\
				mandatory/srcs/lst_map.c\
				mandatory/srcs/draw_map.c\
				mandatory/srcs/draw_line.c\
				mandatory/srcs/error_handler.c\
				mandatory/srcs/mlx_handler.c\
				mandatory/srcs/utils.c

SRCS_BONUS	=	bonus/srcs_bonus/main_bonus.c\
				bonus/srcs_bonus/key_manager_bonus.c\
				bonus/srcs_bonus/key_manager_utils_bonus.c\
				bonus/srcs_bonus/get_next_line_bonus.c\
				bonus/srcs_bonus/parsing_bonus.c\
				bonus/srcs_bonus/lst_map_bonus.c\
				bonus/srcs_bonus/draw_map_bonus.c\
				bonus/srcs_bonus/draw_line_bonus.c\
				bonus/srcs_bonus/error_handler_bonus.c\
				bonus/srcs_bonus/mlx_handler_bonus.c\
				bonus/srcs_bonus/utils_bonus.c

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

.c.o:
	$(CC) $(CFLAGS) -Imlx -c -I./ $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS)
	$(CC) -lmlx -framework OpenGL -framework AppKit $(NAME) -o $(EXEC) -lm

$(NAME_BONUS):	$(OBJS_BONUS)
	ar -rc $(NAME_BONUS) $(OBJS_BONUS)
	$(CC) -lmlx -framework OpenGL -framework AppKit $(NAME_BONUS) -o $(EXEC_BONUS) -lm

all:	$(NAME)

bonus:	$(NAME_BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean:	clean
	$(RM) $(NAME) $(EXEC)
	$(RM) $(NAME_BONUS) $(EXEC_BONUS)

re:	fclean all


.PHONY:	all clean fclean re
