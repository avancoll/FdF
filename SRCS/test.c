/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:34:52 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/05 15:35:04 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	test1(t_data *data, int dx, int dy)
{
	int	p;

	p = 2 * (dy - dx);
	if (map->y < SIZE_Y && map->x < SIZE_X && map->x > -1 && map->y > -1)
  	  mlx_put_pixel(data, x, y, 0x00FF0000);
	while (map->x0 <= map->x1 && map->y0 <= map->y1)
	{
		if (p >= 0)
		{
			p = p + (2 * (dy - dx));
			map->y0++;
		}
    else
			p = p + (2 * dy);
    map->x0++;
		mlx_put_pixel(data, x, y, 0x00FF0000);
	}
}

void	draw_line(t_data *data)
{
	int		dx;
	int		dy;

  dx = abs(x0 - x1);
  dy = abs(y0 - y1);
	if (map->x0 >= map->x1)
	{
		if (dx >= dy)
			test1(map, dx, dy);
		else if (dx < dy)
			test2(map, dx, dy);
	}
	else if (map->x0 < map->x1)
	{
		if (dx > dy)
			test3(map, dx, dy);
		else if (dx <= dy)
			test4(map, dx, dy);
	}
}
void	case1(t_data *data, int dx, int dy)
{
	int	p;

	p = 2 * (dy - dx);
	if (y0 < 1080 && x0 < 1920
		&& x0 > -1 && y0 > -1)
		dr_pixel(data->img, x0, y0, data->ci->color);
	while (x0 <= x1 && y0 <= y1)
	{
		if (p < 0)
		{
			p = p + (2 * dy);
			x0++;
		}
		else if (p >= 0)
		{
			p = p + (2 * (dy - dx));
			x0++;
			y0++;
		}
		if (x0 <= x1 && y0 <= y1
			&& y0 < 1080 && x0 < 1920
			&& x0 > -1 && y0 > -1)
			color_and_pixel(data);
	}
}

void	case2(t_data *data, int dx, int dy)
{
	int	p;

	p = 2 * (dx - dy);
	if (y0 < 1080 && x0 < 1920
		&& x0 > -1 && y0 > -1)
		dr_pixel(data->img, x0, y0, data->ci->color);
	while (x0 <= x1 && y0 <= y1)
	{
		if (p <= 0)
		{
			p = p + (2 * dx);
			y0++;
		}
		else if (p > 0)
		{
			p = p + (2 * (dx - dy));
			x0++;
			y0++;
		}
		if (x0 <= x1 && y0 <= y1
			&& y0 < 1080 && x0 < 1920
			&& x0 > -1 && y0 > -1)
			color_and_pixel(data);
	}
}

void	case3(t_data *data, int dx, int dy)
{
	int	p;

	p = 2 * (dy - dx);
	if (y0 < 1080 && x0 < 1920
		&& x0 > -1 && y0 > -1)
		dr_pixel(data->img, x0, y0, data->ci->color);
	while (x1 <= x0 && y1 >= y0)
	{
		if (p <= 0)
		{
			p = p + (2 * dy);
			x0--;
		}
		else if (p > 0)
		{
			p = p + (2 * (dy - dx));
			x0--;
			y0++;
		}
		if (x1 <= x0 && y1 >= y0
			&& y0 < 1080 && x0 < 1920
			&& x0 > -1 && y0 > -1)
			color_and_pixel(data);
	}
}

void	case4(t_data *data, int dx, int dy)
{
	int	p;

	p = 2 * (dx - dy);
	if (y0 < 1080 && x0 < 1920
		&& x0 > -1 && y0 > -1)
		dr_pixel(data->img, x0, y0, data->ci->color);
	while (x1 <= x0 && y1 >= y0)
	{
		if (p < 0)
		{
			p = p + (2 * dx);
			y0++;
		}
		else if (p >= 0)
		{
			p = p + (2 * (dx - dy));
			x0--;
			y0++;
		}
		if (x1 <= x0 && y1 >= y0
			&& y0 < 1080 && x0 < 1920
			&& x0 > -1 && y0 > -1)
			color_and_pixel(data);
	}
}

void	dr_line(t_data *data, int event)
{
	t_color	c;
	int		dx;
	int		dy;

	c.event = event;
	ft_swap(data);
	find_delta(data, &dy, &dx);
	set_color(data, 0, &c);
	if (x1 >= x0)
	{
		if (dx >= dy)
			case1(data, dx, dy, &c);
		else if (dx < dy)
			case2(data, dx, dy, &c);
	}
	else if (x1 < x0)
	{
		if (dx > dy)
			case3(data, dx, dy, &c);
		else if (dx <= dy)
			case4(data, dx, dy, &c);
	}
