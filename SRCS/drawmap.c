/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:10 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/22 17:50:27 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_map(t_data *data, t_coo *coo)
{
	float	X = 0;
	float	Y = 0;

	float	A = 0;
	float	B = -35;
	float	C = -45;

	int	ax = 0;
	int	ay = 0;
	while (ax < coo->x_max)
	{
		ay = 0;
		while (ay < coo->y_max)
		{
			X = (30 * ax * (cos(B) * cos(C))) + (30 * ay * ((sin(A) * sin(B) * cos(C)) - (cos(A) * sin(C)))) + (3 * coo->xyz[ax][ay] * ((cos(A) * sin(B) * cos(C)) + (sin(A) * sin(C)))) + data->offset_x;
			Y = (30 * ax * (cos(B) * sin(C))) + (30 * ay * ((sin(A) * sin(B) * sin(C)) - (cos(A) * cos(B)))) + (3 * coo->xyz[ax][ay] * ((cos(A) * sin(B) * sin(C)) - (sin(A) * cos(C)))) + data->offset_y;
			if (coo->xyz[ax][ay] == 0)
				mlx_put_pixel(data, X, Y, 0x00FF0000);
			else
				mlx_put_pixel(data, X, Y, 0x00ff1e);
			ay++;
		}
		ax++;
	}
	}
