/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:10 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/05 18:52:53 by avancoll         ###   ########.fr       */
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

void	draw_line1(t_data *data, int x0, int y0, int x1, int y1)//left to right
{
	int	p;
	int	dx;
	int	dy;
	int	x;
	int	y;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	x = x0;
	y = y0;
	p = 2 * (dy - dx);
	while (x <= x1 && y <= y1)
	{
		if (p >= 0)
		{
			p += 2 * (dy - dx);
			y++;
		}
		else
			p += (2 * dy);
		x++;
		mlx_put_pixel(data, x, y, 0x00FF0000);
	}
}

void	draw_line2(t_data *data, int x0, int y0, int x1, int y1)//right to left
{
	int	p;
	int	dx;
	int	dy;
	int	x;
	int	y;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	x = x0;
	y = y0;
	p = 2 * (dy - dx);
	while (x <= x1 && y <= y1)
	{
		if (p <= 0)
		{
			p += (2 * dx);
			x++;
		}
		else
			p += 2 * (dx - dy);
		mlx_put_pixel(data, x, y, 0x00FF0000);
		y++;
	}
}

void	draw_line3(t_data *data, int x0, int y0, int x1, int y1)//up to down
{
	int	p;
	int	dx;
	int	dy;
	int	x;
	int	y;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	x = x0;
	y = y0;
	p = 2 * (dx - dy);
	while (x >= x1 && y <= y1)
	{
		if (p <= 0)
			p += (2 * dy);
		else
		{
			p += 2 * (dy - dx);
			y++;
		}
		mlx_put_pixel(data, x, y, 0x00FF0000);
		x--;
	}
}

void	draw_line4(t_data *data, int x0, int y0, int x1, int y1)//down to up
{
	int	p;
	int	dx;
	int	dy;
	int	x;
	int	y;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	x = x0;
	y = y0;
	p = 2 * (dx - dy);
	while (x >= x1 && y <= y1)
	{
		if (p >= 0)
		{
			p += 2 * (dx - dy);
			x--;
		}
		else
			p += (2 * dx);
		mlx_put_pixel(data, x, y, 0x00FF0000);
		y++;
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
			if (data->coo->z[ax][ay] == 0 && color == 0)
			{
				draw_line1(data, x0, y0, x1, y1);
				draw_line2(data, x0, y0, x1, y1);
				// draw_line3(data, x0, y0, x1, y1);
				// draw_line4(data, x0, y0, x1, y1);
			}
		}
		ax++;
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
	while (ay < data->coo->y_max)
	{
		ax = 0;
		while (ax < data->coo->x_max - 1)
		{
			x0 = x_calc(data->coo, data->key, ax, ay);
			y0 = y_calc(data->coo, data->key, ax, ay);
			x1 = x_calc(data->coo, data->key, ++ax, ay);
			y1 = y_calc(data->coo, data->key, ax, ay);
			if (data->coo->z[ax][ay] == 0 && color == 0)
			{
				// draw_line1(data, x0, y0, x1, y1);
				// draw_line2(data, x0, y0, x1, y1);
				draw_line3(data, x0, y0, x1, y1);
				draw_line4(data, x0, y0, x1, y1);
			}
		}
		ay++;
	}
}
/*
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
*/