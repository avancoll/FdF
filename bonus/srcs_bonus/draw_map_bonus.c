/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:10 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/23 17:10:46 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf_bonus.h"

float	x_calc(t_data *data)
{
	float	x;
	float	a;
	float	b;
	float	c;

	a = data->key->a * M_PI / 180;
	b = data->key->b * M_PI / 180;
	c = data->key->c * M_PI / 180;
	x = data->draw->ax * (cos(b) * cos(c));
	x += data->draw->ay * (sin(a) * sin(b) * cos(c) - cos(a) * sin(c));
	x += data->key->h * data->coo->z[data->draw->ax][data->draw->ay]
		* (cos(a) * sin(b) * cos(c) + sin(a) * sin(c));
	x *= data->key->zoom;
	x += data->key->offset_x;
	return (x);
}

float	y_calc(t_data *data)
{
	float	y;
	float	a;
	float	b;
	float	c;

	a = data->key->a * M_PI / 180;
	b = data->key->b * M_PI / 180;
	c = data->key->c * M_PI / 180;
	y = data->draw->ax * (cos(b) * sin(c));
	y += data->draw->ay * (sin(a) * sin(b) * sin(c) + cos(a) * cos(c));
	y += data->key->h * data->coo->z[data->draw->ax][data->draw->ay]
		* (cos(a) * sin(b) * sin(c) - sin(a) * cos(c));
	y *= data->key->zoom;
	y += data->key->offset_y;
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

void	draw_map2(t_data *data, int event)
{
	data->draw->ay = 0;
	while (data->draw->ay < data->coo->y_max)
	{
		data->draw->ax = 0;
		while (data->draw->ax < data->coo->x_max - 1)
		{
			data->draw->x0 = x_calc(data);
			data->draw->y0 = y_calc(data);
			data->draw->ax++;
			data->draw->x1 = x_calc(data);
			data->draw->y1 = y_calc(data);
			if (event == 0)
				bresenham(data, data->key->base_color);
			else if (event == 1)
				bresenham(data, data->key->background_color);
		}
		data->draw->ay++;
	}
}

void	draw_map(t_data *data, int event)
{
	data->draw->ax = 0;
	while (data->draw->ax < data->coo->x_max)
	{
		data->draw->ay = 0;
		while (data->draw->ay < data->coo->y_max - 1)
		{
			data->draw->x0 = x_calc(data);
			data->draw->y0 = y_calc(data);
			data->draw->ay++;
			data->draw->x1 = x_calc(data);
			data->draw->y1 = y_calc(data);
			if (event == 0)
				bresenham(data, data->key->base_color);
			else if (event == 1)
				bresenham(data, data->key->background_color);
		}
		data->draw->ax++;
	}
	draw_map2(data, event);
}
