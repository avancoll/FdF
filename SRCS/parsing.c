/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:13 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/29 17:05:37 by avancoll         ###   ########.fr       */
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
		if (s[i] && s[i] == ',')
			i += 9;
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i] && s[i] != '-' && (s[i] < '0' || s[i] > '9'))
			break ;
	}
	return (count);
}

t_list	*list_creator(char *argv)
{
	int		fd;
	char	*line;
	t_list	*map;
	t_list	*new;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	map = ft_lstnew(line);
	if (!line || !map)
		return (NULL);
	map->y = int_counter(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line && map->y != int_counter(line))
			return (NULL);
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
	if (str[*i] && str[*i] == ',')
			(*i) += 9;
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

t_coo	*ft_free_int(int **z, int x)
{
	while (x >= 0)
		free(z[x--]);
	free(z);
	return (NULL);
}

t_coo	*list_to_int(t_list *map, t_coo *coo)
{
	int		i;
	int		x;
	int		y;

	coo->x_max = map->x;
	coo->y_max = map->y;
	coo->z = malloc(sizeof(*coo->z) * coo->x_max);
	if (!coo->z)
		return (NULL);
	x = -1;
	while (++x < coo->x_max)
	{
		coo->z[x] = malloc(sizeof(int) * coo->y_max);
		if (!coo->z[x])
			return (ft_free_int(coo->z, x));
		i = 0;
		y = -1;
		while (++y < coo->y_max)
			coo->z[x][y] = ft_atoi(map->content, &i);
		map = map->next;
	}
	return (coo);
}
