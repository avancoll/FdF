/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:13 by avancoll          #+#    #+#             */
/*   Updated: 2022/11/16 18:02:59 by avancoll         ###   ########.fr       */
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
	line = get_next_line(fd);
	map = ft_lstnew(line);
	map->y = int_counter(line);
	while (line)
	{
		line = get_next_line(fd); //attention protection
		new = ft_lstnew(line);
		ft_lstadd_back(&map, new);
	}
	map->x = ft_lstsize(map) - 2;
	close(fd);
	return (map);
}

int	**test(t_list *map)
{
	int	**xyz;
	int	x;
	int	y;
	int	max_x;
	int	max_y;

	x = 0;
	y = 0;
	max_x = map->x;
	max_y = map->y;
	xyz = malloc(sizeof(*xyz) * max_x);
	while (x <= max_x)
	{
		xyz[x] = malloc(sizeof(int) * max_y);
		map = map->next;
		printf("%s", map->content);
		x++;
	}
	return (xyz);
}
