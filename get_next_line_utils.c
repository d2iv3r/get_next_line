/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:39:34 by efarhat           #+#    #+#             */
/*   Updated: 2022/12/03 17:14:24 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	int		len;

	len = ft_strlen(s);
	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (s + len);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (s + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s, char *buff)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
	{
		s = (char *)malloc(1 * sizeof(char));
		if (!s)
			return (NULL);
		s[0] = '\0';
	}
	if (!buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i] != '\0')
		str[i] = s[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(s) + ft_strlen(buff)] = '\0';
	free(s);
	return (str);
}
