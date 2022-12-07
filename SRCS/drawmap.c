/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:10 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/07 16:28:26 by avancoll         ###   ########.fr       */
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

void	draw_line1(t_data *data, t_draw *draw, int color)
{
	int	p;
	int	dx;
	int	dy;
	int	x;
	int	y;

	x = draw->x0;
	y = draw->y0;
	dx = fabsf(draw->x1 - draw->x0);
	dy = fabsf(draw->y1 - draw->y0);
	p = 2 * (dy - dx);
	while (x <= draw->x1 && y <= draw->y1)
	{
		if (p < 0)
		{
			mlx_put_pixel(data, x++, y, color);
			p += 2 * dy;
		}
		else
		{
			mlx_put_pixel(data, x++, y++, color);
			p += 2 * (dy - dx);
		}
	}
}

void	draw_line2(t_data *data, t_draw *draw, int color)
{
	int	p;
	int	dx;
	int	dy;
	int	x;
	int	y;

	x = draw->x0;
	y = draw->y0;
	dx = fabsf(draw->x1 - draw->x0);
	dy = fabsf(draw->y1 - draw->y0);
	p = 2 * (dx - dy);
	while (x <= draw->x1 && y <= draw->y1)
	{
		if (p <= 0)
		{
			mlx_put_pixel(data, x, y++, color);
			p += 2 * dx;
		}
		else
		{
			mlx_put_pixel(data, x++, y++, color);
			p += 2 * (dx - dy);
		}
	}
}

void	draw_line3(t_data *data, t_draw *draw, int color)
{
	int	p;
	int	dx;
	int	dy;
	int	x;
	int	y;

	x = draw->x0;
	y = draw->y0;
	dx = fabsf(draw->x1 - draw->x0);
	dy = fabsf(draw->y1 - draw->y0);
	p = 2 * (dy - dx);
	while (draw->x1 <= x && draw->y1 >= y)
	{
		if (p <= 0)
		{
			mlx_put_pixel(data, x--, y, color);
			p += 2 * dy;
		}
		else
		{
			mlx_put_pixel(data, x--, y++, color);
			p += 2 * (dy - dx);
		}
	}
}

void	draw_line4(t_data *data, t_draw *draw, int color)
{
	int	p;
	int	dx;
	int	dy;
	int	x;
	int	y;

	x = draw->x0;
	y = draw->y0;
	dx = fabsf(draw->x1 - draw->x0);
	dy = fabsf(draw->y1 - draw->y0);
	p = 2 * (dx - dy);
	while (draw->x1 <= x && draw->y1 >= y)
	{
		if (p < 0)
		{
			mlx_put_pixel(data, x, y++, color);
			p += 2 * dx;
		}
		else
		{
			mlx_put_pixel(data, x--, y++, color);
			p += 2 * (dx - dy);
		}
	}
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

void	bresenham(t_data *data, t_draw *draw, int color)
{
	int		dx;
	int		dy;

	ft_swap(draw);
	dx = fabsf(draw->x1 - draw->x0);
	dy = fabsf(draw->y1 - draw->y0);
	if (draw->x1 >= draw->x0)
	{
		if (dx >= dy)
			draw_line1(data, draw, color);
		else
			draw_line2(data, draw, color);
	}
	else
	{
		if (dx > dy)
			draw_line3(data, draw, color);
		else
			draw_line4(data, draw, color);
	}
}

void	draw_map2(t_data *data, t_draw *draw, int color)
{
	int		ax;
	int		ay;

	ay = 0;
	while (ay < data->coo->y_max)
	{
		ax = 0;
		while (ax < data->coo->x_max - 1)
		{
			draw->x0 = x_calc(data->coo, data->key, ax, ay);
			draw->y0 = y_calc(data->coo, data->key, ax, ay);
			draw->x1 = x_calc(data->coo, data->key, ++ax, ay);
			draw->y1 = y_calc(data->coo, data->key, ax, ay);
			if (color == 0)
				bresenham(data, draw, 0x00FF0000);
			else if (color == 1)
				bresenham(data, draw, 0x000000);
		}
		ay++;
	}
}

void	draw_map(t_data *data, t_draw *draw, int color)
{
	int		ax;
	int		ay;

	ax = 0;
	while (ax < data->coo->x_max)
	{
		ay = 0;
		while (ay < data->coo->y_max - 1)
		{
			draw->x0 = x_calc(data->coo, data->key, ax, ay);
			draw->y0 = y_calc(data->coo, data->key, ax, ay);
			draw->x1 = x_calc(data->coo, data->key, ax, ++ay);
			draw->y1 = y_calc(data->coo, data->key, ax, ay);
			if (color == 0)
				bresenham(data, draw, 0x00FF0000);
			else if (color == 1)
				bresenham(data, draw, 0x000000);
		}
		ax++;
	}
	draw_map2(data, draw, color);
}
