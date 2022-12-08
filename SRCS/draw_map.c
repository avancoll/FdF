/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:10 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/08 16:50:23 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	x_calc(t_coo *coo, t_key *key, int ax, int ay)
{
	float	x;
	float	a;
	float	b;
	float	c;

	a = key->a * M_PI / 180;
	b = key->b * M_PI / 180;
	c = key->c * M_PI / 180;
	x = ax * (cos(b) * cos(c));
	x += ay * (sin(a) * sin(b) * cos(c) - cos(a) * sin(c));
	x += key->h * coo->z[ax][ay] * (cos(a) * sin(b) * cos(c) + sin(a) * sin(c));
	x *= key->zoom;
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
	y = ax * (cos(b) * sin(c));
	y += ay * (sin(a) * sin(b) * sin(c) + cos(a) * cos(c));
	y += key->h * coo->z[ax][ay] * (cos(a) * sin(b) * sin(c) - sin(a) * cos(c));
	y *= key->zoom;
	y += key->offset_y;
	return (y);
}

void	ft_swap(t_draw *draw)
{
	int	temp;

	if (draw->y0 > draw->y1)
	{
		temp = draw->x0;
		draw->x0 = draw->x1;
		draw->x1 = temp;
		temp = draw->y0;
		draw->y0 = draw->y1;
		draw->y1 = temp;
	}
}

void	draw_map(t_data *data, int event)
{
	int		ax;
	int		ay;

	ax = 0;
	while (ax < data->coo->x_max)
	{
		ay = 0;
		while (ay < data->coo->y_max - 1)
		{
			data->draw->x0 = x_calc(data->coo, data->key, ax, ay);
			data->draw->y0 = y_calc(data->coo, data->key, ax, ay);
			data->draw->x1 = x_calc(data->coo, data->key, ax, ++ay);
			data->draw->y1 = y_calc(data->coo, data->key, ax, ay);
			if (event == 0)
				bresenham(data, data->key->color);
			else if (event == 1)
				bresenham(data, data->key->background_color);
		}
		ax++;
	}
	draw_map2(data, event);
}

void	draw_map2(t_data *data, int event)
{
	int		ax;
	int		ay;

	ay = 0;
	while (ay < data->coo->y_max)
	{
		ax = 0;
		while (ax < data->coo->x_max - 1)
		{
			data->draw->x0 = x_calc(data->coo, data->key, ax, ay);
			data->draw->y0 = y_calc(data->coo, data->key, ax, ay);
			data->draw->x1 = x_calc(data->coo, data->key, ++ax, ay);
			data->draw->y1 = y_calc(data->coo, data->key, ax, ay);
			if (event == 0)
				bresenham(data, data->key->color);
			else if (event == 1)
				bresenham(data, data->key->background_color);
		}
		ay++;
	}
}
