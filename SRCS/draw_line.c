/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:31:20 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/07 16:34:25 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
