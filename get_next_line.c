/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:40:04 by efarhat           #+#    #+#             */
/*   Updated: 2022/12/03 18:27:08 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *s)
{
	char	*buff;
	int		rdd;

	rdd = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(s, '\n') && rdd > 0)
	{
		rdd = read(fd, buff, BUFFER_SIZE);
		if (rdd == -1)
		{
			free(buff);
			free(s);
			return (NULL);
		}
		buff[rdd] = '\0';
		s = ft_strjoin(s, buff);
	}
	free(buff);
	return (s);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_remaining(char *str)
{
	int		i;
	int		j;
	char	*rem;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	rem = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rem)
		return (NULL);
	i++;
	while (str[i + j] != '\0')
	{
		rem[j] = str[i + j];
		j++;
	}
	rem[j] = '\0';
	free(str);
	return (rem);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	buff = ft_read(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_get_line(buff);
	buff = ft_get_remaining(buff);
	return (line);
}
