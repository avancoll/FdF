/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:19:13 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/08 15:33:48 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close(t_data *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

void	background_filler(t_data *data, int color)
{
	int	x;
	int	y;

	data->key->background_color = color;
	y = 0;
	while (y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
			mlx_put_pixel(data, x++, y, data->key->background_color);
		y++;
	}
}

int	exec_move2(t_data *data)
{
	if (data->key->angle_a_up == 1)
		data->key->a += 1;
	if (data->key->angle_a_down == 1)
		data->key->a -= 1;
	if (data->key->angle_b_up == 1)
		data->key->b += 1;
	if (data->key->angle_b_down == 1)
		data->key->b -= 1;
	if (data->key->angle_c_up == 1)
		data->key->c += 1;
	if (data->key->angle_c_down == 1)
		data->key->c -= 1;
	if (data->key->h_up == 1)
		data->key->h += 0.1;
	if (data->key->h_down == 1)
		data->key->h -= 0.1;
	if (data->key->zoom_up == 1)
		data->key->zoom += 1;
	if (data->key->zoom_down == 1 && data->key->zoom >= 3)
		data->key->zoom -= 1;
	return (0);
}

int	exec_move(t_data *data)
{
	if (data->key->mv_left == 1)
		data->key->offset_x -= 50;
	if (data->key->mv_right == 1)
		data->key->offset_x += 50;
	if (data->key->mv_up == 1)
		data->key->offset_y -= 50;
	if (data->key->mv_down == 1)
		data->key->offset_y += 50;
	if (data->key->background_color_check == 1)
		background_filler(data, 0x979797);
	if (data->key->background_color_check == 2)
		background_filler(data, 0x0);
	exec_move2(data);
	draw_map(data, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	draw_map(data, 1);
	return (0);
}
