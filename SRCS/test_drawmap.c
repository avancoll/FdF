/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_drawmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:10 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/21 17:20:57 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_map(t_data *data, t_coo *coo)
{
	(void)coo;
	int	i = 0;
	float	A = 0;
	float	B = -35.264 * (M_PI / 180);
	float	C = -45 * (M_PI / 180);
	data->x = 0;
	data->y = 0;
	while (i < 500)
	{
		data->x = i;
		data->y = 0;
		data->x = data->x * (cos(B) * cos(C)) + data->y * ((sin(A) * sin(B) * cos(C)) - (cos(A) * sin(C)));
		data->y = data->x * (cos(B) * sin(C)) + data->y * ((sin(A) * sin(B) * sin(C)) - (cos(A) * cos(B)));
		// data->x = data->x * cos(C) - 0 * sin(C);
		// data->y = data->y * cos(B) - 0 * sin(B);
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
		data->x = data->x * (cos(B) * cos(C)) + data->y * ((sin(A) * sin(B) * cos(C)) - (cos(A) * sin(C)));
		data->y = data->x * (cos(B) * sin(C)) + data->y * ((sin(A) * sin(B) * sin(C)) - (cos(A) * cos(B)));
		// data->x = data->x * cos(C) - 0 * sin(C);
		// data->y = data->y * cos(B) - 0 * sin(B);
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
		data->x = data->x * (cos(B) * cos(C)) + data->y * ((sin(A) * sin(B) * cos(C)) - (cos(A) * sin(C)));
		data->y = data->x * (cos(B) * sin(C)) + data->y * ((sin(A) * sin(B) * sin(C)) - (cos(A) * cos(B)));
		// data->x = data->x * cos(C) - 0 * sin(C);
		// data->y = data->y * cos(B) - 0 * sin(B);
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
		data->x = data->x * (cos(B) * cos(C)) + data->y * ((sin(A) * sin(B) * cos(C)) - (cos(A) * sin(C)));
		data->y = data->x * (cos(B) * sin(C)) + data->y * ((sin(A) * sin(B) * sin(C)) - (cos(A) * cos(B)));
		// data->x = data->x * cos(C) - 0 * sin(C);
		// data->y = data->y * cos(B) - 0 * sin(B);
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
		data->x = data->x * (cos(B) * cos(C)) + data->y * ((sin(A) * sin(B) * cos(C)) - (cos(A) * sin(C)));
		data->y = data->x * (cos(B) * sin(C)) + data->y * ((sin(A) * sin(B) * sin(C)) - (cos(A) * cos(B)));
		// data->y = data->y * cos(B) - 1000 * sin(B);
		// data->x = data->x * cos(C) - 1000 * sin(C);
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
		data->x = data->x * (cos(B) * cos(C)) + data->y * ((sin(A) * sin(B) * cos(C)) - (cos(A) * sin(C)));
		data->y = data->x * (cos(B) * sin(C)) + data->y * ((sin(A) * sin(B) * sin(C)) - (cos(A) * cos(B)));
		// data->x = data->x * cos(C) - 1000 * sin(C);
		// data->y = data->y * cos(B) - 1000 * sin(B);
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
		data->x = data->x * (cos(B) * cos(C)) + data->y * ((sin(A) * sin(B) * cos(C)) - (cos(A) * sin(C)));
		data->y = data->x * (cos(B) * sin(C)) + data->y * ((sin(A) * sin(B) * sin(C)) - (cos(A) * cos(B)));
		// data->x = data->x * cos(C) - 1000 * sin(C);
		// data->y = data->y * cos(B) - 1000 * sin(B);
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
		data->x = data->x * (cos(B) * cos(C)) + data->y * ((sin(A) * sin(B) * cos(C)) - (cos(A) * sin(C)));
		data->y = data->x * (cos(B) * sin(C)) + data->y * ((sin(A) * sin(B) * sin(C)) - (cos(A) * cos(B)));
		// data->x = data->x * cos(C) - 1000 * sin(C);
		// data->y = data->y * cos(B) - 1000 * sin(B);
		data->x += SIZE_X /2;
		data->y += SIZE_Y /2;
		// printf("x = %d et y = %d\n", data->x, data->y);
		mlx_put_pixel(data, data->x, data->y, 0x00FF0000);
		i++;
	}
}
