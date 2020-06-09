/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 09:31:44 by gchopin           #+#    #+#             */
/*   Updated: 2020/06/03 20:50:40 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		clear_memory(char **str, int type)
{
	size_t i;

	i = 0;
	if (type == 0)
	{
		while (str[i])
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
		return (-1);
	}
	if (*str && type == 1)
	{
		free(*str);
		*str = NULL;
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
	char	*mem_tmp;

	if (!*m_line || (*m_line)[0] == '\0')
	{
		if (!(mem_tmp = ft_substr(*line, 0, ft_len(*line))))
			return (clear_memory(line, 1));
	}
	else
	{
		if (!(mem_tmp = ft_substr(*m_line, 0, ft_len(*m_line))))
			return (clear_memory(m_line, 0));
	}
	free(*m_line);
	*m_line = mem_tmp;
	if (!(mem_tmp = ft_strdup(*m_line)))
		return (clear_memory(m_line, 0));
	free(*line);
	*line = mem_tmp;
	if (!(mem_tmp = ft_substr(*m_line, length_line(*m_line, res), ft_len(*m_line))))
		return (clear_memory(m_line, 0));
	free(*m_line);
	*m_line = mem_tmp;
	if ((*m_line)[0] == 0 ||*res == -1 ||*res == 0)
		clear_memory(m_line, 1);
	return (*res);
}

int		read_line(int fd, char **line, char **mem_line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(*line, buff)))
			return (clear_memory(line, 1));
		free(*line);
		*line = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret == -1)
		return (clear_memory(mem_line, 0));
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*m_line[9999];
	char		*mem_tmp;
	int			res;

	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	*line[0] = '\0';
	if (m_line[fd] && m_line[fd][0] != 0 && ft_strchr(m_line[fd], '\n') != 0)
		return (get_last_n(line, &m_line[fd], &res));
	res = read_line(fd, line, &m_line[fd]);
	if (res != -1)
	{
		if (m_line[fd] && m_line[fd][0] != 0 && !ft_strchr(m_line[fd], '\n'))
		{
			if (!(mem_tmp = ft_strjoin(m_line[fd], *line)))
				return (clear_memory(m_line, 0));
			free(m_line[fd]);
			m_line[fd] = mem_tmp;
		}
		res = get_last_n(line, &m_line[fd], &res);
	}
	return (res);
}
