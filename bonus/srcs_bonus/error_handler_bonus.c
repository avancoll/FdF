/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:48:15 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/23 17:12:31 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf_bonus.h"

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

char	*free_char(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

t_coo	*free_map(t_list *map, t_coo *coo, int **z, int x)
{
	t_list	*temp;

	while (x >= 0)
		free(z[x--]);
	free(z);
	while (map)
	{
		free(map->content);
		temp = map;
		map = map->next;
		free(temp);
	}
	if (map)
		free(map);
	if (coo)
		free(coo);
	return (NULL);
}
