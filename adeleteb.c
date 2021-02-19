/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:39:43 by gchopin           #+#    #+#             */
/*   Updated: 2021/02/19 02:54:46 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putstr_fd(char *s, int fd)
{
	size_t i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
void	ft_putnbr_fd(ssize_t n, int fd)
{
	if (n < 0)
	{
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
int	clear_memory(char **str, char **str_two, int type)
{
	size_t	i;

	i = 0;
	if (str && type == 1)
	{
		free(*str);
		*str = NULL;
	}
	if (str_two)
	{
		while (str_two != 0 && 10241 > i)
		{
			if (str && type == 0)
			{
				free(str[i]);
				str[i] = NULL;
			}
			free(str_two[i]);
			str_two[i] = NULL;
			i++;
		}
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
#include <stdio.h>
int	get_last_n(char **line, char **m_ln, int *res, int fd)
{
	char	*m_tmp;

	if (!m_ln)
		return (clear_memory(line, 0, 1));
	if (!m_ln[fd] || m_ln[fd][0] == '\0')
		m_tmp = ft_substr(*line, 0, ft_len(*line));
	else
		m_tmp = ft_substr(m_ln[fd], 0, ft_len(m_ln[fd]));
	if (m_tmp == NULL)
		return (clear_memory(line, m_ln, 1));
	free(m_ln[fd]);
	m_ln[fd] = m_tmp;
	m_tmp = ft_strdup(m_ln[fd]);
	if (m_tmp == NULL)
		return (clear_memory(line, m_ln, 1));
	free(*line);
	*line = m_tmp;
	m_tmp = ft_substr(m_ln[fd], len_n(m_ln[fd], res), ft_len(m_ln[fd]));
	if (m_tmp == NULL)
		return (clear_memory(line, m_ln, 1));
	free(m_ln[fd]);
	m_ln[fd] = m_tmp;
	if (m_ln[fd] == NULL || m_ln[fd][0] == 0 || *res == -1 || *res == 0)
		clear_memory(&m_ln[fd], 0, 1);
	//printf("*gnl_line=%s ", *line);
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
			return (clear_memory(line, mem_line, 1));
		buff[ret] = '\0';
		tmp = ft_strjoin(*line, buff);
		if (tmp == NULL)
			return (clear_memory(line, 0, 1));
		free(*line);
		*line = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	//printf("fd=%d ret=%d buff=%s line=%s ", fd, ret, buff, *line);
	ft_putstr_fd("fd=", 1);ft_putnbr_fd(fd, 1);ft_putstr_fd("line=", 1);ft_putstr_fd(*line, 1);
	if (ret == -1)
		return (clear_memory(line, mem_line, 1));
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	ft_putnbr_fd(fd, 1);
	static char	*m_line[10241];
	char		*mem_tmp;
	int			res;
//printf("BUFFER_SIZE=%d ", BUFFER_SIZE);
	if (BUFFER_SIZE < 1 || fd < 0 || fd > 10240 || !line)
		return (-1);
	*line = NULL;
		char c;
	if (m_line[fd] && m_line[fd][0] != 0 && ft_strchr(m_line[fd], '\n') != 0)
	{
		ft_putstr_fd("fdB=", 1);ft_putnbr_fd(fd, 1);write(1, &c, 1);ft_putstr_fd("m_line=", 1);ft_putstr_fd(m_line[fd], 1);
		return (get_last_n(line, m_line, &res, fd));
	}
	res = read_line(fd, line, m_line);
	//printf("m_line=%s ", m_line[fd]);
	if (res != -1)
	{
		if (m_line[fd] && m_line[fd][0] != 0 && !ft_strchr(m_line[fd], '\n'))
		{
			mem_tmp = ft_strjoin(m_line[fd], *line);
			if (mem_tmp == NULL)
				return (clear_memory(line, m_line, 1));
			free(m_line[fd]);
			m_line[fd] = mem_tmp;
		}
		res = get_last_n(line, m_line, &res, fd);
		//printf("fd=%d m_line=%s ", fd, m_line[fd]);
		c = ' ';
	}
	printf("fd=%d p=%p ", fd, m_line[fd]);ft_putstr_fd("fdA=", 1);ft_putnbr_fd(fd, 1);write(1, &c, 1);ft_putstr_fd("m_line=", 1);ft_putstr_fd(m_line[3], 1);ft_putstr_fd(" ", 1);
	return (res);
}
