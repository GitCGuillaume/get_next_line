/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:02:07 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/22 15:05:43 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		read_line(int fd, char **line)
{
	printf("hi");
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;
	int			response;
	
	response = -1;
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	*line[0] = '\0';
	while ((ret = read(fd, buff, BUFFER_SIZE)))
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

int		length_line(char *str, int *result)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		i++;
		*result = 1;
	}
	//else if (str[i] == '\0')
	//	*result = 0;
	return (i);
}

void	static_process(char **line, char **static_line, int *result)
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
		tmp_static = ft_substr(*static_line, 0, ft_len(*static_line));
		free(*static_line);
		*static_line = tmp_static;
	}
	printf("static_line == %s\n", *static_line);
	if (!(tmp = ft_strdup(*static_line)))
		*result = -1;
	if (!(*static_line = ft_substr(*static_line, i, ft_len(*static_line))))
		*result = -1;
	free(*line);
	*line = tmp;
	printf("line == %s", *line);
}
/*
int		get_n(char **line)
{

}*/

int		get_next_line(int fd, char **line)
{
	int			result;
	static char	*static_line;
	
	result = -1;
	if (!static_line)
		static_line = NULL;
	if (BUFFER_SIZE < 1 || fd <= 0 || !line)
		return (-1);
	//if (fd != -1 && BUFFER_SIZE >= 1 && static_line != 0)
	//{
	//	return (0);
	//}
	//get_last_n(line, &static_line, &result);
	if (!static_line || static_line[0] == 0)
		result = read_line(fd, line);
	if (fd != -1 && BUFFER_SIZE >= 1)
		static_process(line, &static_line, &result);
	return (result);
}
