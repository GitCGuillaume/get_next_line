/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:02:07 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/20 18:07:02 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		read_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;
	int			response;

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
		return (0);
	return (response);
}

int		get_last_n(char **line, char **static_line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while ((*line)[i] != '\0' && (*line)[i] != '\n')
		i++;
	printf("i == %zu\n", i);
	printf("ft_len == %zu", ft_len(*line));
	*static_line = ft_substr(*line, i, ft_len(*line));
	tmp = ft_strdup(*line);
	free(*line);
	*line = tmp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			result;
	static char	*static_line;
	
	result = -1;
	if (BUFFER_SIZE < 1 || fd <= 0 || !line)
		return (-1);
	/*if (static_line > 0 && fd != -1)
	{
		free(*line);
		*line = static_line;
	}*/
	result = read_line(fd, line);
	if (result != -1 && fd != -1 && *line)
		get_last_n(line, &static_line);
	printf("*line final == %s\n", *line);
	return (result);
}
