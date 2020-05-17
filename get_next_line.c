/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:02:07 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/17 22:50:12 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		read_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;

	if (!(*line = malloc(sizeof(char))))
		return (-1);
	*line[0] = '\0';
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buff)))
			return (-1);
		free(tmp);
		printf("%s\n", *line);
		printf("ret == %d\n", ret);
		if (ft_strchr(buff, '\n'))
			break;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int		result;

	result = read_line(fd, line);
	printf("result == %d\n", result);
	return (1);
}
