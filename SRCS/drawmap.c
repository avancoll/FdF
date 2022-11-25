/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:10 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/25 15:47:59 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// void	set_color(t_data *data, int ax, int ay, int color)
// {

// }

void	draw_map(t_data *data, int color)
{
	float	x;
	float	y;
	float	rad_a;
	float	rad_b;
	float	rad_c;
	int		ax;
	int		ay;

	x = 0;
	y = 0;
	ax = 0;
	ay = 0;
	rad_a = data->key->a * M_PI / 180;
	rad_b = data->key->b * M_PI / 180;
	rad_c = data->key->c * M_PI / 180;
	while (ax < data->coo->x_max)
	{
		ay = 0;
		while (ay < data->coo->y_max)
		{
			x = (data->key->zoom * ax * (cos(rad_b) * cos(rad_c))) + (data->key->zoom * ay * ((sin(rad_a) * sin(rad_b) * cos(rad_c)) - (cos(rad_a) * sin(rad_c)))) + (data->key->height * data->coo->xyz[ax][ay] * ((cos(rad_a) * sin(rad_b) * cos(rad_c)) + (sin(rad_a) * sin(rad_c)))) + data->key->offset_x;
			y = (data->key->zoom * ax * (cos(rad_b) * sin(rad_c))) + (data->key->zoom * ay * ((sin(rad_a) * sin(rad_b) * sin(rad_c)) + (cos(rad_a) * cos(rad_c)))) + (data->key->height * data->coo->xyz[ax][ay] * ((cos(rad_a) * sin(rad_b) * sin(rad_c)) - (sin(rad_a) * cos(rad_c)))) + data->key->offset_y;
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
