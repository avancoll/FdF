/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:22:41 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/29 17:01:19 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < SIZE_X && y < SIZE_Y)
	{
		dst = data->addr + (y * data->size_line + x * (data->bits_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	init_data(t_data *data)
{
	data->key->offset_x = SIZE_X / 2;
	data->key->offset_y = SIZE_Y / 3;
	data->key->a = 35;
	data->key->b = 150;
	data->key->c = -45;
	data->key->h = 10;
	data->key->zoom = 30;
}

int	malloc_data(t_data *data)
{
	data->key = malloc(sizeof(t_key));
	if (!data->key)
		return (0);
	data->coo = malloc(sizeof(t_coo));
	if (!data->coo)
		return (0);
	data->map = malloc(sizeof(t_list));
	if (!data->map)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		check;

	if (argc != 2)
		return (1);
	check = malloc_data(&data);
	if (!check)
		return (1);
	data.map = list_creator(argv[1]);
	if (!data.map)
		return (1);
	data.coo = list_to_int(data.map, data.coo);
	if (!data.coo)
		return (1);
	init_data(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, SIZE_X, SIZE_Y, "fdf");
	data.img_ptr = mlx_new_image(data.mlx_ptr, SIZE_X, SIZE_Y);
	data.addr = mlx_get_data_addr(data.img_ptr, &data.bits_pixel,
			&data.size_line, &data.endian);
	mlx_hook(data.win_ptr, ON_DESTROY, 0, ft_close, &data);
	mlx_hook(data.win_ptr, ON_KEYUP, 0, key_released, &data);
	mlx_hook(data.win_ptr, ON_KEYDOWN, 0, key_pressed, &data);
	mlx_loop_hook(data.mlx_ptr, exec_move, &data);
	mlx_loop(data.mlx_ptr);
}
