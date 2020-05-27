/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 08:51:48 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/27 11:54:55 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		clear_memory(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	return (-1);
}

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
			return (clear_memory(line));
		free(*line);
		*line = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
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
	{
		if (!(*static_line = ft_substr(*line, 0, ft_len(*line))))
			return (*result = clear_memory(static_line));
	}
	else
	{
		if (!(tmp_static = ft_substr(*static_line, 0, ft_len(*static_line))))
			return (*result = clear_memory(static_line));
		free(*static_line);
		*static_line = tmp_static;
	}
	if (!(tmp = ft_strdup(*static_line)))
		return (*result = clear_memory(static_line));
	if (!(*static_line = ft_substr(*static_line,
					length_line(*static_line, result), ft_len(*static_line))))
		return (*result = clear_memory(static_line));
	free(*line);
	*line = tmp;
	return (*result);
}

int		get_next_line(int fd, char **line)
{
	int			result;
	static char *mem_line;
	char		*tmp;

	result = -1;
	if (BUFFER_SIZE < 1 || fd <= 0 || !line)
		return (-1);
	if (!mem_line)
		mem_line = NULL;
	if (fd != -1 && (!mem_line || mem_line[0] == 0 || mem_line == NULL))
		result = read_line(fd, line);
	else
	{
		result = read_line(fd, line);
		if (!(tmp = ft_strjoin(mem_line, *line)))
			return (result = clear_memory(line));
		free(mem_line);
		mem_line = tmp;
	}
	if (fd != -1 && BUFFER_SIZE >= 1 && result >= 0)
		if ((result = get_last_n(line, &mem_line, &result)) == -1)
			clear_memory(line);
	return (result);
}
