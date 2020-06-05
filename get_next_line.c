/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 09:31:44 by gchopin           #+#    #+#             */
/*   Updated: 2020/06/05 11:17:03 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		clear_memory(char **str, int type)
{
	printf("addr_clear==%p\n", *str);
	size_t i;

	i = 0;
	if (type == 0)
	{
		while (str[i])
		{	
			free(str[i]);
			i++;
		}
	}
	else
	{
		if (*str)
		{
			free(*str);
			printf("addr_efface=%p\n", *str);
		}
	}
	return (-1);
}

int		length_line(char *str, int *res)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
		{
			*res = 1;
			i++;
		}
	}
	return (i);
}

int		get_last_n(char **line, char **m_line, int *res)
{
	char	*tmp;
	char	*mem_tmp;
	printf("ml_addr2==%p", *m_line);
	if (!*m_line ||  (*m_line)[0] == '\0')
	{
		if (!(*m_line = ft_substr(*line, 0, ft_len(*line))))
			return (clear_memory(line, 0));
	}
	else
	{
		if (!(mem_tmp = ft_substr(*m_line, 0, ft_len(*m_line))))
			return (clear_memory(m_line, 1));
		free(*m_line);
		*m_line = mem_tmp;
	}
	if (!(tmp = ft_strdup(*m_line)))
		return (clear_memory(m_line, 1));
	if (!(*m_line = ft_substr(*m_line,
					length_line(*m_line, res), ft_len(*m_line))))
		return (clear_memory(m_line, 1));
	printf("ml_addr3==%p", *m_line);
	free(*line);
	*line = tmp;
	if (*res == 0)
	{
		printf("fin mem_line\n");
		clear_memory(m_line, 1);
	}
	return (*res);
}

int		read_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(*line, buff)))
			return (clear_memory(line, 0));
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
	printf("addr_ml1=%p", mem_line[fd]);
	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	*line[0] = '\0';
	if (mem_line[fd] && mem_line[fd][0] != 0
			&& ft_strchr(mem_line[fd], '\n') != 0)
		return (get_last_n(line, &mem_line[fd], &res));
	res = read_line(fd, line);
	if (res == -1)
		return (clear_memory(&mem_line[fd], 1));
	if (mem_line[fd] && mem_line[fd][0] != 0 && !ft_strchr(mem_line[fd], '\n'))
	{
		if (!(mem_tmp = ft_strjoin(mem_line[fd], *line)))
			return (clear_memory(mem_line, 0));
		free(mem_line[fd]);
		mem_line[fd] = mem_tmp;
	}
	return (get_last_n(line, &mem_line[fd], &res));
}
