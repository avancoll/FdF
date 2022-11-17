/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:22:41 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/17 16:08:23 by avancoll         ###   ########.fr       */
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
	data->x = SIZE_X / 2;
	data->y = SIZE_Y / 2;
	data->mv_right = 0;
	data->mv_up = 0;
	data->mv_down = 0;
	data->mv_left = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_list	*map;
	t_coo	coo;

	if (argc != 2)
		return (0);
	map = list_creator(argv[1]);
	coo.xyz = list_to_int(map);
	init_data(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, SIZE_X, SIZE_Y, "fdf");
	data.img_ptr = mlx_new_image(data.mlx_ptr, SIZE_X, SIZE_Y);
	data.addr = mlx_get_data_addr(data.img_ptr, &data.bits_pixel,
			&data.size_line, &data.endian);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_hook(data.win_ptr, ON_DESTROY, 0, ft_close, &data);
	mlx_hook(data.win_ptr, ON_KEYUP, 0, key_released, &data);
	mlx_hook(data.win_ptr, ON_KEYDOWN, 0, key_pressed, &data);
	mlx_loop_hook(data.mlx_ptr, exec_move, &data);
	mlx_loop(data.mlx_ptr);
}
