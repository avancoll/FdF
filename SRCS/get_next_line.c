/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avancoll <avancoll@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:37:08 by avancoll          #+#    #+#             */
/*   Updated: 2022/12/19 17:00:17 by avancoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_get_line(char *save)
{
	int		i;
	char	*res;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		res[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		res[i] = save[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_after_line(char *save)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (ft_free(save, NULL));
	res = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!res)
		return (ft_free(save, NULL));
	i++;
	j = 0;
	while (save[i])
		res[j++] = save[i++];
	res[j] = 0;
	free(save);
	return (res);
}

char	*ft_read(int fd, char *save)
{
	char	*buff;
	int		check;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	check = 1;
	while (!ft_strchr(save, '\n') && check)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (check == -1)
			return (ft_free(buff, save));
		buff[check] = 0;
		save = ft_strjoin_free(save, buff);
		if (!save)
			return (ft_free(buff, NULL));
	}
	free(buff);
	if (save[0] == 0 && check == 0)
		return (ft_free(save, NULL));
	return (save);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	while (s1[i])
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	if (!line)
		return (ft_free(save, NULL));
	save = ft_after_line(save);
	return (line);
}
