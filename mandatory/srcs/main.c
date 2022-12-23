/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:22:41 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/23 17:46:15 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_sizer2(t_data *data)
{
	if (data->coo->x_max <= 100 && data->coo->y_max <= 150)
	{
		data->key->zoom = 10;
		data->key->offset_x = 960;
		data->key->offset_y = 30;
	}
	else if (data->coo->x_max <= 150 && data->coo->y_max <= 200)
	{
		data->key->zoom = 6;
		data->key->offset_x = 760;
		data->key->offset_y = 80;
	}
	else if (data->coo->x_max <= 200 && data->coo->y_max <= 250)
	{
		data->key->zoom = 4;
		data->key->offset_x = 960;
		data->key->offset_y = 180;
	}
	else
	{
		data->key->zoom = 2;
		data->key->offset_x = 960;
		data->key->offset_y = 30;
	}
}

void	map_sizer(t_data *data)
{
	if (data->coo->x_max <= 15 && data->coo->y_max <= 15)
	{
		data->key->zoom = 50;
		data->key->offset_x = 960;
		data->key->offset_y = 350;
	}
	else if (data->coo->x_max <= 20 && data->coo->y_max <= 50)
	{
		data->key->zoom = 50;
		data->key->offset_x = 800;
		data->key->offset_y = 100;
	}
	else if (data->coo->x_max <= 50 && data->coo->y_max <= 100)
	{
		data->key->offset_x = 900;
		data->key->offset_y = 50;
		data->key->zoom = 20;
	}
	else
		map_sizer2(data);
}

void	init_data(t_data *data)
{
	data->key->a = 35;
	data->key->b = 150;
	data->key->c = -45;
	data->key->h = 0.5;
	map_sizer(data);
}

int	malloc_data(t_data *data)
{
	data->key = malloc(sizeof(t_key));
	if (!data->key)
		return (0);
	data->coo = malloc(sizeof(t_coo));
	if (!data->coo)
		return (0);
	data->map = NULL;
	data->draw = malloc(sizeof(t_draw));
	if (!data->draw)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		check;

	if (argc != 2)
		return (error_handler(1));
	check = filename_checker(argv[1]);
	if (!check)
		return (error_handler(3));
	check = malloc_data(&data);
	if (!check)
		return (error_handler(4));
	data.map = list_creator(argv[1]);
	if (!data.map)
		return (free_data(&data, 2));
	data.coo = list_to_int(data.map, data.coo);
	if (!data.coo)
		return (free_data(&data, 4));
	mlx_handler(&data);
	init_data(&data);
	mlx_hook(data.win_ptr, ON_DESTROY, 0, ft_close, &data);
	mlx_hook(data.win_ptr, ON_KEYDOWN, 0, key_pressed, &data);
	draw_map(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_loop(data.mlx_ptr);
}
