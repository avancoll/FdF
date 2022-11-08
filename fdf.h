/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:20:32 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/08 15:51:40 by avancoll         ###   ########.fr       */
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

char	*ft_free(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_get_line(char *save);
char	*ft_after_line(char *save);
char	*ft_read(int fd, char *save);
char	*get_next_line(int fd);

#endif
