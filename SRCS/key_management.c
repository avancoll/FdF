/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:25:51 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/24 17:07:52 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_close(t_data *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_close(data);
	if (keycode == KEY_UP)
		data->key->mv_up = 1;
	if (keycode == KEY_DOWN)
		data->key->mv_down = 1;
	if (keycode == KEY_LEFT)
		data->key->mv_left = 1;
	if (keycode == KEY_RIGHT)
		data->key->mv_right = 1;
	if (keycode == KEY_W)
		data->key->angle_A_up = 1;
	if (keycode == KEY_S)
		data->key->angle_A_down = 1;
	if (keycode == KEY_A)
		data->key->angle_B_up = 1;
	if (keycode == KEY_D)
		data->key->angle_B_down = 1;
	if (keycode == KEY_Q)
		data->key->angle_C_up = 1;
	if (keycode == KEY_E)
		data->key->angle_C_down = 1;
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == KEY_UP)
		data->key->mv_up = 0;
	if (keycode == KEY_DOWN)
		data->key->mv_down = 0;
	if (keycode == KEY_LEFT)
		data->key->mv_left = 0;
	if (keycode == KEY_RIGHT)
		data->key->mv_right = 0;
	if (keycode == KEY_W)
		data->key->angle_A_up = 0;
	if (keycode == KEY_S)
		data->key->angle_A_down = 0;
	if (keycode == KEY_A)
		data->key->angle_B_up = 0;
	if (keycode == KEY_D)
		data->key->angle_B_down = 0;
	if (keycode == KEY_Q)
		data->key->angle_C_up = 0;
	if (keycode == KEY_E)
		data->key->angle_C_down = 0;
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
	if (data->key->angle_A_up == 1)
		data->key->A += 1;
	if (data->key->angle_A_down == 1)
		data->key->A -= 1;
	if (data->key->angle_B_up == 1)
		data->key->B += 1;
	if (data->key->angle_B_down == 1)
		data->key->B -= 1;
	if (data->key->angle_C_up == 1)
		data->key->C += 1;
	if (data->key->angle_C_down == 1)
		data->key->C -= 1;
	draw_map(data, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	draw_map(data, 1);
	return (0);
}
