/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:20:32 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/17 16:07:11 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h> //open
# include <unistd.h> //close read write
# include <stdlib.h> //malloc free
# include <stdio.h> // perror
# include <string.h> //strerror
# include <stdlib.h> //exit
# include <math.h> // maths
# include <mlx.h> //minilibx
# include <limits.h> //limits

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_Q = 12,
	KEY_E = 14,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126
};

enum {
	SIZE_X = 1920,
	SIZE_Y = 1080,
	BUFFER_SIZE = 42
};

typedef struct s_list
{
	int				x;
	int				y;
	char			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_data
{
	int		x;
	int		y;
	int		mv_up;
	int		mv_down;
	int		mv_right;
	int		mv_left;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_pixel;
	int		size_line;
	int		endian;
}				t_data;

typedef struct s_coo
{
	int	**xyz;
	int	x_max;
	int	y_max;
}				t_coo;

char	*ft_free(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_get_line(char *save);
char	*ft_after_line(char *save);
char	*ft_read(int fd, char *save);
char	*get_next_line(int fd);

void	mlx_put_pixel(t_data *data, int x, int y, int color);
void	init_data(t_data *data);
int		ft_close(t_data *data);
int		key_pressed(int keycode, t_data *data);
int		key_released(int keycode, t_data *data);
int		exec_move(t_data *data);
// void	draw_map(t_data *data);
t_list	*list_creator(char *argv);
int		**list_to_int(t_list *map);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif
