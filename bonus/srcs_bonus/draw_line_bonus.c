/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:31:20 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/23 17:46:04 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf_bonus.h"

void	draw_line1(t_data *data, int color)
{
	int	p;
	int	x;
	int	y;

	x = data->draw->x0;
	y = data->draw->y0;
	data->draw->dx = abs(data->draw->x1 - data->draw->x0);
	data->draw->dy = abs(data->draw->y1 - data->draw->y0);
	p = 2 * (data->draw->dy - data->draw->dx);
	while (x <= data->draw->x1 && y <= data->draw->y1)
	{
		if (p < 0)
		{
			mlx_put_pixel(data, x++, y, color);
			p += 2 * data->draw->dy;
		}
		else
		{
			mlx_put_pixel(data, x++, y++, color);
			p += 2 * (data->draw->dy - data->draw->dx);
		}
	}
}

void	draw_line2(t_data *data, int color)
{
	int	p;
	int	x;
	int	y;

	x = data->draw->x0;
	y = data->draw->y0;
	data->draw->dx = abs(data->draw->x1 - data->draw->x0);
	data->draw->dy = abs(data->draw->y1 - data->draw->y0);
	p = 2 * (data->draw->dx - data->draw->dy);
	while (x <= data->draw->x1 && y <= data->draw->y1)
	{
		if (p <= 0)
		{
			mlx_put_pixel(data, x, y++, color);
			p += 2 * data->draw->dx;
		}
		else
		{
			mlx_put_pixel(data, x++, y++, color);
			p += 2 * (data->draw->dx - data->draw->dy);
		}
	}
}

void	draw_line3(t_data *data, int color)
{
	int	p;
	int	x;
	int	y;

	x = data->draw->x0;
	y = data->draw->y0;
	data->draw->dx = abs(data->draw->x1 - data->draw->x0);
	data->draw->dy = abs(data->draw->y1 - data->draw->y0);
	p = 2 * (data->draw->dy - data->draw->dx);
	while (data->draw->x1 <= x && data->draw->y1 >= y)
	{
		if (p <= 0)
		{
			mlx_put_pixel(data, x--, y, color);
			p += 2 * data->draw->dy;
		}
		else
		{
			mlx_put_pixel(data, x--, y++, color);
			p += 2 * (data->draw->dy - data->draw->dx);
		}
	}
}

void	draw_line4(t_data *data, int color)
{
	int	p;
	int	x;
	int	y;

	x = data->draw->x0;
	y = data->draw->y0;
	data->draw->dx = abs(data->draw->x1 - data->draw->x0);
	data->draw->dy = abs(data->draw->y1 - data->draw->y0);
	p = 2 * (data->draw->dx - data->draw->dy);
	while (data->draw->x1 <= x && data->draw->y1 >= y)
	{
		if (p < 0)
		{
			mlx_put_pixel(data, x, y++, color);
			p += 2 * data->draw->dx;
		}
		else
		{
			mlx_put_pixel(data, x--, y++, color);
			p += 2 * (data->draw->dx - data->draw->dy);
		}
	}
}

void	bresenham(t_data *data, int color)
{
	ft_swap(data->draw);
	data->draw->dx = abs(data->draw->x1 - data->draw->x0);
	data->draw->dy = abs(data->draw->y1 - data->draw->y0);
	if (data->draw->x1 >= data->draw->x0)
	{
		if (data->draw->dx >= data->draw->dy)
			draw_line1(data, color);
		else
			draw_line2(data, color);
	}
	else
	{
		if (data->draw->dx > data->draw->dy)
			draw_line3(data, color);
		else
			draw_line4(data, color);
	}
}
