/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:10 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/29 17:14:29 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// void	set_color(t_data *data, int ax, int ay, int color)
// {

// }

float	x_calc(t_coo *coo, t_key *key, int ax, int ay)
{
	float	x;
	float	a;
	float	b;
	float	c;

	a = key->a * M_PI / 180;
	b = key->b * M_PI / 180;
	c = key->c * M_PI / 180;
	x = key->zoom * ax * (cos(b) * cos(c));
	x += key->zoom * ay * (sin(a) * sin(b) * cos(c) - cos(a) * sin(c));
	x += key->h * coo->z[ax][ay] * (cos(a) * sin(b) * cos(c) + sin(a) * sin(c));
	x += key->offset_x;
	return (x);
}

float	y_calc(t_coo *coo, t_key *key, int ax, int ay)
{
	float	y;
	float	a;
	float	b;
	float	c;

	a = key->a * M_PI / 180;
	b = key->b * M_PI / 180;
	c = key->c * M_PI / 180;
	y = key->zoom * ax * (cos(b) * sin(c));
	y += key->zoom * ay * (sin(a) * sin(b) * sin(c) + cos(a) * cos(c));
	y += key->h * coo->z[ax][ay] * (cos(a) * sin(b) * sin(c) - sin(a) * cos(c));
	y += key->offset_y;
	return (y);
}

void	draw_map(t_data *data, int color)
{
	float	x;
	float	y;
	int		ax;
	int		ay;

	x = 0;
	y = 0;
	ax = -1;
	while (++ax < data->coo->x_max)
	{
		ay = -1;
		while (++ay < data->coo->y_max)
		{
			x = x_calc(data->coo, data->key, ax, ay);
			y = y_calc(data->coo, data->key, ax, ay);
			if (data->coo->z[ax][ay] == 0 && color == 0)
				mlx_put_pixel(data, x, y, 0x00FF0000);
			else if (data->coo->z[ax][ay] != 0 && color == 0)
				mlx_put_pixel(data, x, y, 0x00ff1e);
			else if (data->coo->z[ax][ay] == 0 && color == 1)
				mlx_put_pixel(data, x, y, 0x000000);
			else if (data->coo->z[ax][ay] != 0 && color == 1)
				mlx_put_pixel(data, x, y, 0x000000);
		}
	}
}
