/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:10 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/06 17:28:13 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// void	set_color(t_data *data, int x, int y, int color)
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
void	draw_line1(t_data *data, int x0, int y0, int x1, int y1)
{
	int	p;
	int	dx;
	int	dy;
	int	x;
	int	y;

	x = x0;
	y = y0;
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	p = 2 * (dy - dx);
	mlx_put_pixel(data, x0, y0, 0x00FF0000);
	while (x <= x1 && y <= y1)
	{
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * (dy - dx);
			y++;
		}
		x++;
		mlx_put_pixel(data, x, y, 0x00FF0000);
	}
}

void	draw_line2(t_data *data, int x0, int y0, int x1, int y1)
{
	int	p;
	int	dx;
	int	dy;
	int	x;
	int	y;

	x = x0;
	y = y0;
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	p = 2 * (dx - dy);
	mlx_put_pixel(data, x0, y0, 0x00FF0000);
	while (x <= x1 && y <= y1)
	{
		if (p <= 0)
			p += 2 * dx;
		else
		{
			p += 2 * (dx - dy);
			x++;
		}
		y++;
		mlx_put_pixel(data, x, y, 0x00FF0000);
	}
}

void	draw_line3(t_data *data, int x0, int y0, int x1, int y1)
{
	int	p;
	int	dx;
	int	dy;
	int	x;
	int	y;

	x = x0;
	y = y0;
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	p = 2 * (dy - dx);
	mlx_put_pixel(data, x0, y0, 0x00FF0000);
	while (x1 <= x && y1 >= y)
	{
		if (p <= 0)
			p += 2 * dy;
		else
		{
			p = p + (2 * (dy - dx));
			y++;
		}
		x--;
		mlx_put_pixel(data, x, y, 0x00FF0000);
	}
}

void	draw_line4(t_data *data, int x0, int y0, int x1, int y1)
{
	int	p;
	int	dx;
	int	dy;
	int	x;
	int	y;

	x = x0;
	y = y0;
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	p = 2 * (dx - dy);
	mlx_put_pixel(data, x0, y0, 0x00FF0000);
	while (x1 <= x && y1 >= y)
	{
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * (dx - dy);
			x--;
		}
		y++;
		mlx_put_pixel(data, x, y, 0x00FF0000);
	}
}

void	bresenham(t_data *data, int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;
	int		temp;

	if (y0 > y1)
	{
		temp = x0;
		x0 = x1;
		x1 = temp;
		temp = y0;
		y0 = y1;
		y1 = temp;
	}
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	if (x1 >= x0)
	{
		if (dx >= dy)
			draw_line1(data, x0, y0, x1, y1);
		else if (dx < dy)
			draw_line2(data, x0, y0, x1, y1);
	}
	else if (x1 < x0)
	{
		if (dx > dy)
			draw_line3(data, x0, y0, x1, y1);
		else if (dx <= dy)
			draw_line4(data, x0, y0, x1, y1);
	}
}

void	draw_map2(t_data *data, int color)
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	int		ax;
	int		ay;

	ay = 0;
	while (ay < data->coo->y_max + 1)
	{
		ax = 0;
		while (ax < data->coo->x_max - 1)
		{
			x0 = x_calc(data->coo, data->key, ax, ay);
			y0 = y_calc(data->coo, data->key, ax, ay);
			x1 = x_calc(data->coo, data->key, ++ax, ay);
			y1 = y_calc(data->coo, data->key, ax, ay);
			if (color == 0)
				bresenham(data, x0, y0, x1, y1);
		}
		ay++;
	}
}

void	draw_map(t_data *data, int color)
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	int		ax;
	int		ay;

	ax = 0;
	while (ax < data->coo->x_max)
	{
		ay = 0;
		while (ay < data->coo->y_max)
		{
			x0 = x_calc(data->coo, data->key, ax, ay);
			y0 = y_calc(data->coo, data->key, ax, ay);
			x1 = x_calc(data->coo, data->key, ax, ++ay);
			y1 = y_calc(data->coo, data->key, ax, ay);
			if (color == 0)
				bresenham(data, x0, y0, x1, y1);
		}
		ax++;
	}
	draw_map2(data, color);
}
