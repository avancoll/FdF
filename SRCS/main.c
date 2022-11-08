/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:22:41 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/08 12:37:11 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0)
	{
		dst = data->addr + (y * data->size_line + x * (data->bits_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, SIZE_X, SIZE_Y, "fdf");
	data.img_ptr = mlx_new_image(data.mlx_ptr, SIZE_X, SIZE_Y);
	data.addr = mlx_get_data_addr(data.img_ptr, &data.bits_pixel,
			&data.size_line, &data.endian);
	mlx_put_pixel(&data, 0, 0, 0x00FF0000);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_put_pixel(&data, 100, 100, 0x00FF0000);
	mlx_hook(data.win_ptr, ON_DESTROY, 0, ft_close, &data);
	mlx_loop(data.mlx_ptr);
}
