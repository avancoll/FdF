/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:48:15 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/19 17:07:57 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	error_handler(int event)
{
	if (event == 1)
		write(1, "Wrong number of argument\n", 26);
	else if (event == 2)
		write(1, "Wrong map\n", 11);
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	res;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	res = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (res);
}

int	filename_checker(char *str)
{
	if (ft_strlen(str) > 4)
		if (ft_strcmp(str + ft_strlen(str) - 4, ".fdf") == 0)
			return (1);
	write(1, "Wrong extension", 16);
	return (0);
}
