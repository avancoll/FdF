/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:13 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/25 16:33:34 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	int_counter(char *s)
{
	int	i;
	int	count;
	int	is_digit;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		is_digit = 0;
		while (s[i] && ((s[i] >= '0' && s[i] <= '9') || s[i] == '-'))
		{
			if (is_digit == 0)
				count++;
			is_digit = 1;
			i++;
		}
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i] == '\n')
			break ;
	}
	return (count);
}

t_list	*list_creator(char *argv)
{
	int		fd;
	char	*line;
	t_list	*new;
	t_list	*map;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	map = ft_lstnew(line);
	if (!map)
		return (map);
	map->y = int_counter(line);
	while (line)
	{
		line = get_next_line(fd);
		new = ft_lstnew(line);
		if (!new)
			return (NULL);
		ft_lstadd_back(&map, new);
	}
	map->x = ft_lstsize(map) - 1;
	close(fd);
	return (map);
}

int	ft_atoi(const char *str, int *i)
{
	unsigned long long		res;
	int						sign;

	res = 0;
	sign = 1;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-')
	{
		(*i)++;
		sign = -sign;
	}
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
		res = res * 10 + str[(*i)++] - 48;
	return (res * sign);
}

int	**ft_free_int(int **xyz, int x)
{
	while (x >= 0)
	{
		free(xyz[x]);
		x--;
	}
	free(xyz);
	return (0);
}

t_coo	*list_to_int(t_list *map, t_coo *coo)
{
	int		i;
	int		x;
	int		y;

	x = 0;
	coo->x_max = map->x;
	coo->y_max = map->y;
	coo->xyz = malloc(sizeof(*coo->xyz) * coo->x_max); //attention protect
	if (!coo->xyz)
		return (0);
	while (x < coo->x_max)
	{
		coo->xyz[x] = malloc(sizeof(int) * coo->y_max); //proetect
		// if (!coo->xyz[x])
		//  	return (ft_free_int(coo->xyz, x));
		i = 0;
		y = 0;
		while (y < coo->y_max)
		{
			coo->xyz[x][y] = ft_atoi(map->content, &i);
			y++;
		}
		map = map->next;
		x++;
	}
	return (coo);
}
