/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:39:43 by gchopin           #+#    #+#             */
/*   Updated: 2021/02/19 17:01:33 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	clear_memory(char **str, char **str_two)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
	if (str_two)
	{
		free(*str_two);
		*str_two = NULL;
	}
	return (-1);
}

int	len_n(char *str, int *res)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
		{
			if (res)
				*res = 1;
			i++;
		}
	}
	return (i);
}

int	get_last_n(char **line, char **m_ln, int *res, int fd)
{
	char	*m_tmp;

	if (!m_ln)
		return (clear_memory(line, 0));
	if (!m_ln[fd] || m_ln[fd][0] == '\0')
		m_tmp = ft_substr(*line, 0, ft_len(*line));
	else
		m_tmp = ft_substr(m_ln[fd], 0, ft_len(m_ln[fd]));
	if (m_tmp == NULL)
		return (clear_memory(line, &m_ln[fd]));
	free(m_ln[fd]);
	m_ln[fd] = m_tmp;
	m_tmp = ft_strdup(m_ln[fd]);
	if (m_tmp == NULL)
		return (clear_memory(line, &m_ln[fd]));
	free(*line);
	*line = m_tmp;
	m_tmp = ft_substr(m_ln[fd], len_n(m_ln[fd], res), ft_len(m_ln[fd]));
	if (m_tmp == NULL)
		return (clear_memory(line, &m_ln[fd]));
	free(m_ln[fd]);
	m_ln[fd] = m_tmp;
	if (m_ln[fd] == NULL || m_ln[fd][0] == 0 || *res == -1 || *res == 0)
		clear_memory(&m_ln[fd], 0);
	return (*res);
}

int	read_line(int fd, char **line, char **mem_line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;

	free(*line);
	*line = ft_strdup("");
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
			return (clear_memory(line, &mem_line[fd]));
		buff[ret] = '\0';
		tmp = ft_strjoin(*line, buff);
		if (tmp == NULL)
			return (clear_memory(line, 0));
		free(*line);
		*line = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret == -1)
		return (clear_memory(line, &mem_line[fd]));
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*m_line[10241];
	char		*mem_tmp;
	int			res;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 10240 || !line)
		return (-1);
	*line = NULL;
	if (m_line[fd] && m_line[fd][0] != 0 && ft_strchr(m_line[fd], '\n') != 0)
		return (get_last_n(line, m_line, &res, fd));
	res = read_line(fd, line, m_line);
	if (res != -1)
	{
		if (m_line[fd] && m_line[fd][0] != 0 && !ft_strchr(m_line[fd], '\n'))
		{
			mem_tmp = ft_strjoin(m_line[fd], *line);
			if (mem_tmp == NULL)
				return (clear_memory(line, &m_line[fd]));
			free(m_line[fd]);
			m_line[fd] = mem_tmp;
		}
		res = get_last_n(line, m_line, &res, fd);
	}
	if (*line == NULL || res == -1)
		return (clear_memory(line, &m_line[fd]));
	return (res);
}
