/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:34:52 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/06 16:51:36 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	test(t_data *data)
{
	int	x = 0;
	int	y = 0;
	int	start_x = SIZE_X / 2;
	int	start_y = SIZE_Y / 2;
	while (x < 1920)
		bresenham(data, start_x, start_y, x++, y);
	while (y < 1080)
		bresenham(data, start_x, start_y, x, y++);
	while (x > -1)
		bresenham(data, start_x, start_y, x--, y);
	while (y > -1)
		bresenham(data, start_x, start_y, x, y--);
}