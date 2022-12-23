/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:25:51 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/23 17:46:01 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf_bonus.h"

int	key_pressed2(int keycode, t_data *data)
{
	if (keycode == KEY_UP)
		data->key->mv_up = 1;
	if (keycode == KEY_DOWN)
		data->key->mv_down = 1;
	if (keycode == KEY_LEFT)
		data->key->mv_left = 1;
	if (keycode == KEY_RIGHT)
		data->key->mv_right = 1;
	if (keycode == KEY_PAD1)
		data->key->background_color_check = 1;
	if (keycode == KEY_PAD2)
		data->key->background_color_check = 2;
	if (keycode == KEY_PAD3)
		data->key->background_color_check = 3;
	if (keycode == KEY_PAD4)
		data->key->color_check = 1;
	if (keycode == KEY_PAD5)
		data->key->color_check = 2;
	if (keycode == KEY_PAD6)
		data->key->color_check = 3;
	if (keycode == KEY_R)
		data->key->reset = 1;
	if (keycode == KEY_P)
		data->key->parallel_view = 1;
	return (0);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_close(data);
	if (keycode == KEY_W)
		data->key->angle_a_up = 1;
	if (keycode == KEY_S)
		data->key->angle_a_down = 1;
	if (keycode == KEY_A)
		data->key->angle_b_up = 1;
	if (keycode == KEY_D)
		data->key->angle_b_down = 1;
	if (keycode == KEY_Q)
		data->key->angle_c_up = 1;
	if (keycode == KEY_E)
		data->key->angle_c_down = 1;
	if (keycode == KEY_PLUS)
		data->key->h_up = 1;
	if (keycode == KEY_MINUS)
		data->key->h_down = 1;
	if (keycode == KEY_Z)
		data->key->zoom_up = 1;
	if (keycode == KEY_X)
		data->key->zoom_down = 1;
	key_pressed2(keycode, data);
	return (0);
}

int	key_released2(int keycode, t_data *data)
{
	if (keycode == KEY_UP)
		data->key->mv_up = 0;
	if (keycode == KEY_DOWN)
		data->key->mv_down = 0;
	if (keycode == KEY_LEFT)
		data->key->mv_left = 0;
	if (keycode == KEY_RIGHT)
		data->key->mv_right = 0;
	if (keycode == KEY_PAD1 || keycode == KEY_PAD2 || keycode == KEY_PAD3)
		data->key->background_color_check = 0;
	if (keycode == KEY_PAD4 || keycode == KEY_PAD5 || keycode == KEY_PAD6)
		data->key->color_check = 0;
	if (keycode == KEY_R)
		data->key->reset = 0;
	if (keycode == KEY_P)
		data->key->parallel_view = 0;
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key->angle_a_up = 0;
	if (keycode == KEY_S)
		data->key->angle_a_down = 0;
	if (keycode == KEY_A)
		data->key->angle_b_up = 0;
	if (keycode == KEY_D)
		data->key->angle_b_down = 0;
	if (keycode == KEY_Q)
		data->key->angle_c_up = 0;
	if (keycode == KEY_E)
		data->key->angle_c_down = 0;
	if (keycode == KEY_PLUS)
		data->key->h_up = 0;
	if (keycode == KEY_MINUS)
		data->key->h_down = 0;
	if (keycode == KEY_Z)
		data->key->zoom_up = 0;
	if (keycode == KEY_X)
		data->key->zoom_down = 0;
	key_released2(keycode, data);
	return (0);
}
