/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 08:51:48 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/26 10:15:03 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		read_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;
	int		response;

	response = -1;
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	*line[0] = '\0';
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		response = 1;
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(*line, buff)))
			return (-1);
		free(*line);
		*line = tmp;
		if (ft_strchr(buff, '\n'))
			break;
	}
	if (ret == 0)
		return (response = 0);
	return (response);
}

int		length_line(char *str, int *result)
{
	size_t i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		i++;
		*result = 1;
	}
	return (i);
}

int		get_last_n(char **line, char **static_line, int *result)
{
	size_t	i;
	char	*tmp;
	char	*tmp_static;

	i = 0;
	if (!*static_line || (*static_line)[0] == '\0')
		i = length_line(*line, result);
	else
		i = length_line(*static_line, result);
	if (!*static_line || (*static_line)[0] == '\0')
		*static_line = ft_substr(*line, 0, ft_len(*line));
	else
	{
		if (!(tmp_static = ft_substr(*static_line, 0, ft_len(*static_line))))
			return (*result = -1);
		free(*static_line);
		*static_line = tmp_static;
	}
	if (!(tmp = ft_strdup(*static_line)))
		return (*result = -1);
	if (!(*static_line = ft_substr(*static_line, i, ft_len(*static_line))))
		return (*result = -1);
	free(*line);
	*line = tmp;
	return (*result);
}

/*int		process_static(char **line, char **static_line, int fd, int *result)
{
	char	*tmp;
	
	*result = read_line(fd, line);
	if (!(tmp = ft_strjoin(*static_line, *line)))
	{
		free(*line);
		return (*result = -1);
	}
	free(*static_line);
	*static_line = tmp;
	return (*result);
}*/

int		get_next_line(int fd, char **line)
{
	int			result;
	static char *mem_line;
	char		*tmp;

	result = -1;
	if (BUFFER_SIZE < 1 || fd <= 0 || !line)
		return (-1);
	if (fd != -1 && (!mem_line || mem_line[0] == 0 || mem_line == NULL))
		result = read_line(fd, line);
	else
	{
		result = read_line(fd, line);
		if (!(tmp = ft_strjoin(mem_line, *line)))
		{
			free(*line);
			return (result = -1);
		}
	}
	if (fd != -1 && BUFFER_SIZE >= 1 && result >= 0)
		result = get_last_n(line, &mem_line, &result);
	return (result);
}
