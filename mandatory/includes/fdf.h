/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:20:32 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/23 17:13:00 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <limits.h>

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
};

enum {
	SIZE_X = 1920,
	SIZE_Y = 1080,
	BUFFER_SIZE = 10000
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
	float	a;
	float	b;
	float	c;
	float	h;
	int		zoom;
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

void	mlx_put_pixel(t_data *data, int x, int y, int color);
void	mlx_handler(t_data *data);
void	init_data(t_data *data);
int		ft_close(t_data *data);
int		key_pressed(int keycode, t_data *data);
int		key_released(int keycode, t_data *data);
int		exec_move(t_data *data);
void	bresenham(t_data *data, int color);
void	background_filler(t_data *data, int color);
void	draw_map(t_data *data);
t_list	*list_creator(char *argv);
t_coo	*list_to_int(t_list *map, t_coo *coo);
void	ft_swap(t_draw *draw);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		filename_checker(char *str);
int		error_handler(int event);
int		free_data(t_data *data, int event);
t_coo	*free_map(t_list *map, t_coo *coo, int **z, int x);
char	*free_char(char *s1, char *s2);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
int		ft_atoi(const char *str, int *i);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
