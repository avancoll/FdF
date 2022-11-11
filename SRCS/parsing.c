/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:13 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/11 17:14:39 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	parse(char *argv)
{
	int		fd;
	char	*line;
	t_list	*new;
	t_list	*map;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	map = ft_lstnew(line);
	printf("[%d]: %s", ft_lstsize(map), map->content);
	while (line)
	{
		line = get_next_line(fd);
		new = ft_lstnew(line);
		ft_lstadd_back(&map, new);
		printf("[%d]: %s", ft_lstsize(map), new->content);
	}
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