/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:02:07 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/19 15:07:16 by gchopin          ###   ########.fr       */
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

int		remove_jump(char **line, char *static_line)
{
	size_t	i;

	i = 0;
	static_line = ft_strdup(*line);
	free(*line);
	*line = static_line;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int		result;
	char	*static_line;

	if (BUFFER_SIZE < 1 || fd <= 0 || !line)
		return (-1);
	static_line = NULL;
	result = read_line(fd, line);
	printf("line1== %s\n", *line);
	if (result != -1 && fd != -1 && *line)
		remove_jump(line, static_line);
	printf("line2== %s\n", *line);
	return (result);
}
