/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:40:36 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/19 17:00:11 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_free(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == 0)
		return (s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			res[i] = s1[i];
	while (s2[j])
		res[i++] = s2[j++];
	res[ft_strlen(s1) + ft_strlen(s2)] = 0;
	free(s1);
	return (res);
}
