/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:48:15 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/22 18:26:01 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	error_handler(int event)
{
	if (event == 1)
		write(1, "Wrong number of argument", 25);
	else if (event == 2)
		write(1, "Wrong map", 10);
	else if (event == 3)
		write(1, "Wrong extension", 16);
	else if (event == 4)
		write(1, "Error due to malloc", 20);
	exit (0);
}

int	filename_checker(char *str)
{
	if (ft_strlen(str) > 4)
		if (ft_strcmp(str + ft_strlen(str) - 4, ".fdf") == 0)
			return (1);
	return (0);
}

int	free_data(t_data *data, int event)
{
	free(data->key);
	free(data->coo);
	free(data->draw);
	return (error_handler(event));
}
