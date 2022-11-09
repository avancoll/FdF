/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:25:51 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/09 16:12:20 by avancoll         ###   ########.fr       */
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
	return (0);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_close(data);
	if (keycode == KEY_W)
		data->mv_up = 1;
	if (keycode == KEY_A)
		data->mv_left = 1;
	if (keycode == KEY_S)
		data->mv_down = 1;
	if (keycode == KEY_D)
		data->mv_right = 1;
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_close(data);
	if (keycode == KEY_W)
		data->mv_up = 0;
	if (keycode == KEY_A)
		data->mv_left = 0;
	if (keycode == KEY_S)
		data->mv_down = 0;
	if (keycode == KEY_D)
		data->mv_right = 0;
	return (0);
}

int	exec_move(t_data *data)
{
	if (data->mv_left == 1)
		mlx_put_pixel(data, --data->x, data->y, 0x00FF0000);
	if (data->mv_right == 1)
		mlx_put_pixel(data, ++data->x, data->y, 0x00FF0000);
	if (data->mv_up == 1)
		mlx_put_pixel(data, data->x, --data->y, 0x00FF0000);
	if (data->mv_down == 1)
		mlx_put_pixel(data, data->x, ++data->y, 0x00FF0000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}
