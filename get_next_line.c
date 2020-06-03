/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 09:31:44 by gchopin           #+#    #+#             */
/*   Updated: 2020/06/03 17:02:08 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		clear_memory(char **str)
{
	size_t i;

	i = 0;
	while (str[i])
		free(str[i]);
	if (str)
		free(str);
	return (-1);
}

int		length_line(char *str)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
			i++;
	}
	return (i);
}

int		get_last_n(char **line, char **m_line)
{
	char	*tmp;
	char	*mem_tmp;

	if (!*m_line || (*m_line)[0] == '\0')
	{
		if (!(*m_line = ft_substr(*line, 0, ft_len(*line))))
			return (clear_memory(m_line));
	}
	else
	{
		if (!(mem_tmp = ft_substr(*m_line, 0, ft_len(*m_line))))
			return (clear_memory(m_line));
		free(*m_line);
		*m_line = mem_tmp;
	}
	if (!(tmp = ft_strdup(*m_line)))
		return (clear_memory(m_line));
	if (!(*m_line = ft_substr(*m_line, length_line(*m_line), ft_len(*m_line))))
		return (clear_memory(m_line));
	free(*line);
	printf("tmp==%s", tmp);
	*line = tmp;
	return (1);
}

int		read_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	//char	*mem_tmp;
	int		ret;

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(*line, buff)))
			return (clear_memory(line));
		free(*line);
		*line = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (!(*line))
		return (-1);
	if (!(*line)[0] || !ft_strchr(*line, '\n'))
		return (0);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*mem_line[OPEN_MAX];
	char		*mem_tmp;
	int			res;

	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	*line[0] = '\0';
	if (mem_line[fd] && mem_line[fd][0] != 0
			&& ft_strchr(mem_line[fd], '\n') != 0)
		return (get_last_n(line, &mem_line[fd]));
	res = read_line(fd, line);
	if (mem_line[fd])
		printf("mem_line=%s", mem_line[fd]);
	printf("line=%s", *line);
	if (mem_line[fd] && mem_line[fd][0] != 0 && !ft_strchr(mem_line[fd], '\n'))
	{
		printf("hi");
		if (!(mem_tmp = ft_strjoin(mem_line[fd], *line)))
			return (clear_memory(mem_line));
		printf("mem_tmp=%s", mem_tmp);
		free(mem_line[fd]);
		mem_line[fd] = mem_tmp;
	}
	if (res < 1)
		return (res);
	return (get_last_n(line, &mem_line[fd]));
}
