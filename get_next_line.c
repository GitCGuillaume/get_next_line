/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 09:31:44 by gchopin           #+#    #+#             */
/*   Updated: 2020/06/01 13:20:57 by gchopin          ###   ########.fr       */
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
	return (-1);
}

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
	return (1);
}

int		length_line(char *str, int *res)
{
	size_t i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		i++;
	//	*res = 1;
	}
	return (i);
}

int		get_last_n(char **line, char **mem_line, int *res)
{
	char	*tmp;
	char	*mem_tmp;

	if (!*mem_line || (*mem_line)[0] == '\0')
	{
		if (!(*mem_line = ft_substr(*line, 0, ft_len(*line))))
			return (*res = clear_memory(mem_line));
	}
	else
	{
		if (!(mem_tmp = ft_substr(*mem_line, 0, ft_len(*mem_line))))
			return (*res = clear_memory(mem_line));
		free(*mem_line);
		*mem_line = mem_tmp;
	}
	if (!(tmp = ft_strdup(*mem_line)))
		return (*res = clear_memory(mem_line));
	if (!(*mem_line = ft_substr(*mem_line, length_line(*mem_line, res), ft_len(*mem_line))))
		return (*res = clear_memory(mem_line));
	if (*line)
	free(*line);
	*line = tmp;
	return (*res);
}

int		get_next_line(int fd, char **line)
{
	static char	*mem_line;
	char		*tmp;
	int			res;

	res = -1;
	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (mem_line && mem_line[0] != 0 && ft_strchr(mem_line, '\n') != 0 /*&& mem_line[0] != 0 && mem_line[length_line(mem_line, &res) - 1] == '\n'*/)
	{
		res = get_last_n(line, &mem_line, &res);
		//return (res);
		if (res == 1)
			return (1);
		else if (res == -1)
			return (-1);
	}
	res = read_line(fd, line);
	if (mem_line && mem_line[0] != 0 && ft_strchr(mem_line, '\n') == 0/*&& mem_line[0] != 0 && mem_line[length_line(mem_line, &res) - 1] != '\n'*/)
	{
		if (!(tmp = ft_strjoin(mem_line, *line)))
			return (res = clear_memory(&mem_line));
		free(mem_line);
		mem_line = tmp;
	}
	res = get_last_n(line, &mem_line, &res);
	return (res);
}
