/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:57:27 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/23 17:12:54 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fdf_bonus.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (free_char(s1, 0));
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

int	ft_atoi(const char *str, int *i)
{
	unsigned int		res;
	int					sign;

	res = 0;
	sign = 1;
	if (str[*i] && str[*i] == ',')
		while (str[*i] && str[*i] != ' ')
			(*i)++;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-')
	{
		(*i)++;
		sign = -sign;
	}
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
		res = res * 10 + str[(*i)++] - 48;
	if (res >= INT_MAX / 8)
		res = 0;
	return (res * sign);
}
