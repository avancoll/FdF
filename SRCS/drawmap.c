/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:10 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/24 17:27:05 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_map(t_data *data, int color)
{
	float	x;
	float	y;
	float	rad_A;
	float	rad_B;
	float	rad_C;
	int	ax;
	int	ay;

	x = 0;
	y = 0;
	ax = 0;
	ay = 0;
	rad_A = data->key->A * M_PI / 180;
	rad_B = data->key->B * M_PI / 180;
	rad_C = data->key->C * M_PI / 180;

	while (ax < data->coo->x_max)
	{
		ay = 0;
		while (ay < data->coo->y_max)
		{
			x = (30 * ax * (cos(rad_B) * cos(rad_C))) + (30 * ay * ((sin(rad_A) * sin(rad_B) * cos(rad_C)) - (cos(rad_A) * sin(rad_C)))) + (3 * data->coo->xyz[ax][ay] * ((cos(rad_A) * sin(rad_B) * cos(rad_C)) + (sin(rad_A) * sin(rad_C)))) + data->key->offset_x;
			y = (30 * ax * (cos(rad_B) * sin(rad_C))) + (30 * ay * ((sin(rad_A) * sin(rad_B) * sin(rad_C)) + (cos(rad_A) * cos(rad_C)))) + (3 * data->coo->xyz[ax][ay] * ((cos(rad_A) * sin(rad_B) * sin(rad_C)) - (sin(rad_A) * cos(rad_C)))) + data->key->offset_y;
			if (data->coo->xyz[ax][ay] == 0 && color == 0)
				mlx_put_pixel(data, x, y, 0x00FF0000);
			else if (data->coo->xyz[ax][ay] != 0 && color == 0)
				mlx_put_pixel(data, x, y, 0x00ff1e);
			else if (data->coo->xyz[ax][ay] == 0 && color == 1)
				mlx_put_pixel(data, x, y, 0x000000);
			else if (data->coo->xyz[ax][ay] != 0 && color == 1)
				mlx_put_pixel(data, x, y, 0x000000);
			ay++;
		}
		ax++;
	}
	}
