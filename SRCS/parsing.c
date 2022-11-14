/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:13 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/14 17:38:55 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	int_counter(char *s)
{
	int	i;
	int	count;
	int	is_digit;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		is_digit = 0;
		while (s[i] && ((s[i] >= '0' && s[i] <= '9') || s[i] == '-'))
		{
			if (is_digit == 0)
				count++;
			is_digit = 1;
			i++;
		}
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i] == '\n')
			break ;
	}
	return (count);
}

void	parse(char *argv)
{
	int		fd;
	char	*line;
	t_list	*new;
	t_list	*map;
	int		x;
	int		y;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	map = ft_lstnew(line);
	x = ft_lstsize(map) - 1;
	y = int_counter(line);
	printf("[x = %d, y = %d]: %s", ft_lstsize(map) - 1, int_counter(line), map->content);
	while (line)
	{
		line = get_next_line(fd);
		new = ft_lstnew(line);
		ft_lstadd_back(&map, new);
		printf("[x = %d, y = %d]: %s", ft_lstsize(map) - 1, int_counter(line), new->content);
	}
	close(fd);
}

void	draw_map(t_data *data)
{
	int	i = 0;
	float	A = 45 * (M_PI / 180);
	float	B = (sin(30) / cos(45)) * (M_PI / 180);
	float	C = 0;

	data->x = 0;
	data->y = 0;
	while (i < 500)
	{
		data->x = i;
		data->y = 0;
		data->x = (data->x) * cos(A) - (data->y) * sin(A);
		data->y = (data->x) * sin(A) + (data->y) * cos(A);
		data->x = data->x;
		data->y = data->y * cos(B) - 0 * sin(B);
		data->x = data->x * cos(C) - 0 * sin(C);
		data->y = data->y;
		data->x += SIZE_X /2;
		data->y += SIZE_Y /2;
		// printf("x = %d et y = %d\n", data->x, data->y);
		mlx_put_pixel(data, data->x, data->y, 0x00FF0000);
		i++;
	}
	i = 0;
	data->x = 0;
	data->y = 0;
	while (i < 500)
	{
		data->x = 0;
		data->y = i;
		data->x = (data->x) * cos(A) - (data->y) * sin(A);
		data->y = (data->x) * sin(A) + (data->y) * cos(A);
		data->x = data->x;
		data->y = data->y * cos(B) - 0 * sin(B);
		data->x = data->x * cos(C) - 0 * sin(C);
		data->y = data->y;
		data->x += SIZE_X /2;
		data->y += SIZE_Y /2;
		// printf("x = %d et y = %d\n", data->x, data->y);
		mlx_put_pixel(data, data->x, data->y, 0x00FF0000);
		i++;
	}
	i = 0;
	data->x = 0;
	data->y = 0;
	while (i < 500)
	{
		data->x = i;
		data->y = 500;
		data->x = (data->x) * cos(A) - (data->y) * sin(A);
		data->y = (data->x) * sin(A) + (data->y) * cos(A);
		data->x = data->x;
		data->y = data->y * cos(B) - 0 * sin(B);
		data->x = data->x * cos(C) - 0 * sin(C);
		data->y = data->y;
		data->x += SIZE_X /2;
		data->y += SIZE_Y /2;
		// printf("x = %d et y = %d\n", data->x, data->y);
		mlx_put_pixel(data, data->x, data->y, 0x00FF0000);
		i++;
	}
	i = 0;
	data->x = 0;
	data->y = 0;
	while (i < 500)
	{
		data->x = 500;
		data->y = i;
		data->x = (data->x) * cos(A) - (data->y) * sin(A);
		data->y = (data->x) * sin(A) + (data->y) * cos(A);
		data->x = data->x;
		data->y = data->y * cos(B) - 0 * sin(B);
		data->x = data->x * cos(C) - 0 * sin(C);
		data->y = data->y;
		data->x += SIZE_X /2;
		data->y += SIZE_Y /2;
		// printf("x = %d et y = %d\n", data->x, data->y);
		mlx_put_pixel(data, data->x, data->y, 0x00FF0000);
		i++;
	}
	i = 0;
	data->x = 0;
	data->y = 0;
	while (i < 500)
	{
		data->x = i;
		data->y = 0;
		data->x = (data->x) * cos(A) - (data->y) * sin(A);
		data->y = (data->x) * sin(A) + (data->y) * cos(A);
		data->x = data->x;
		data->y = data->y * cos(B) - 1000 * sin(B);
		data->x = data->x * cos(C) - 1000 * sin(C);
		data->y = data->y;
		data->x += SIZE_X /2;
		data->y += SIZE_Y /2;
		// printf("x = %d et y = %d\n", data->x, data->y);
		mlx_put_pixel(data, data->x, data->y, 0x00FF0000);
		i++;
	}
	i = 0;
	data->x = 0;
	data->y = 0;
	while (i < 500)
	{
		data->x = 0;
		data->y = i;
		data->x = (data->x) * cos(A) - (data->y) * sin(A);
		data->y = (data->x) * sin(A) + (data->y) * cos(A);
		data->x = data->x;
		data->y = data->y * cos(B) - 1000 * sin(B);
		data->x = data->x * cos(C) - 1000 * sin(C);
		data->y = data->y;
		data->x += SIZE_X /2;
		data->y += SIZE_Y /2;
		// printf("x = %d et y = %d\n", data->x, data->y);
		mlx_put_pixel(data, data->x, data->y, 0x00FF0000);
		i++;
	}
	i = 0;
	data->x = 0;
	data->y = 0;
	while (i < 500)
	{
		data->x = i;
		data->y = 500;
		data->x = (data->x) * cos(A) - (data->y) * sin(A);
		data->y = (data->x) * sin(A) + (data->y) * cos(A);
		data->x = data->x;
		data->y = data->y * cos(B) - 1000 * sin(B);
		data->x = data->x * cos(C) - 1000 * sin(C);
		data->y = data->y;
		data->x += SIZE_X /2;
		data->y += SIZE_Y /2;
		// printf("x = %d et y = %d\n", data->x, data->y);
		mlx_put_pixel(data, data->x, data->y, 0x00FF0000);
		i++;
	}
	i = 0;
	data->x = 0;
	data->y = 0;
	while (i < 500)
	{
		data->x = 500;
		data->y = i;
		data->x = (data->x) * cos(A) - (data->y) * sin(A);
		data->y = (data->x) * sin(A) + (data->y) * cos(A);
		data->x = data->x;
		data->y = data->y * cos(B) - 1000 * sin(B);
		data->x = data->x * cos(C) - 1000 * sin(C);
		data->y = data->y;
		data->x += SIZE_X /2;
		data->y += SIZE_Y /2;
		// printf("x = %d et y = %d\n", data->x, data->y);
		mlx_put_pixel(data, data->x, data->y, 0x00FF0000);
		i++;
	}
}
