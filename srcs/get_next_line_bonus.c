/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:00:16 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/02 14:58:13 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_substr(char *line, int start)
{
	int		i;
	int		j;
	int		len;
	char	*substr;

	len = ft_strlen(line + start);
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = start;
	j = -1;
	while (++j < len)
		substr[j] = line[i + j];
	substr[len] = '\0';
	free(line);
	return (substr);
}

char	*ft_find_next_line(char *line, char **res)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		*res = ft_strndup(line, i + 1);
		line = ft_substr(line, i + 1);
	}
	else
	{
		*res = ft_strndup(line, i);
		free(line);
		line = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			nb_byte_read;
	static char	*line[1024];
	char		*res;

	if (line[fd] == NULL || line[fd][0] == '\0')
	{
		free(line[fd]);
		line[fd] = NULL;
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer != NULL)
			nb_byte_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer == NULL || nb_byte_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		line[fd] = ft_strndup(buffer, nb_byte_read);
		free(buffer);
	}
	line[fd] = ft_find_next_line(line[fd], &res);
	if (line[fd] == NULL)
		res = ft_concat(res, get_next_line(fd));
	return (res);
}
