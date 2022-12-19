/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:20:32 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/19 17:05:21 by avancoll         ###   ########.fr       */
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
	KEY_UP = 126,
	KEY_Z = 6,
	KEY_X = 7,
	KEY_PAD1 = 83,
	KEY_PAD2 = 84,
	KEY_PAD3 = 85,
	KEY_PAD4 = 86,
	KEY_PAD5 = 87,
	KEY_PAD6 = 88,
	KEY_MINUS = 27,
	KEY_PLUS = 24,
	KEY_R = 15,
	KEY_P = 35,
	KEY_TAB = 48
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

typedef struct s_coo
{
	int	**z;
	int	x_max;
	int	y_max;
}				t_coo;

typedef struct s_key
{
	int		offset_x;
	int		offset_y;
	int		mv_up;
	int		mv_down;
	int		mv_left;
	int		mv_right;
	float	a;
	float	b;
	float	c;
	int		angle_a_up;
	int		angle_a_down;
	int		angle_b_up;
	int		angle_b_down;
	int		angle_c_up;
	int		angle_c_down;
	float	h;
	int		zoom;
	int		h_up;
	int		h_down;
	int		zoom_up;
	int		zoom_down;
	int		background_color;
	int		base_color;
	int		background_color_check;
	int		color_check;
	int		reset;
	int		parallel_view;
	int		menu;
}				t_key;

typedef struct s_draw
{
	int	ax;
	int	ay;
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
}				t_draw;

typedef struct s_data
{
	struct s_coo	*coo;
	struct s_key	*key;
	struct s_list	*map;
	struct s_draw	*draw;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr;
	int				bits_pixel;
	int				size_line;
	int				endian;
}				t_data;

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
int		exec_move2(t_data *data);
int		exec_move3(t_data *data);
void	draw_map(t_data *data, int event);
void	draw_map2(t_data *data, int event);
t_list	*list_creator(char *argv);
t_coo	*list_to_int(t_list *map, t_coo *coo);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

void	draw_line1(t_data *data, int color);
void	draw_line2(t_data *data, int color);
void	draw_line3(t_data *data, int color);
void	draw_line4(t_data *data, int color);
void	bresenham(t_data *data, int color);
void	ft_swap(t_draw *draw);
void	background_filler(t_data *data, int color);
int		error_handler(int event);
int		filename_checker(char *str);

#endif
