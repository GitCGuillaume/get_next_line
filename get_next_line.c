/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 09:31:44 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/29 20:32:17 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		clear_memory(char **str)
{
	printf("???????");
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
	return (ret);
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
		*res = 1;
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
		{
			printf("A\n");
			return (*res = clear_memory(mem_line));
		}
	}
	else
	{
		if (!(mem_tmp = ft_substr(*mem_line, 0, ft_len(*mem_line))))
		{
			printf("I\n");
			return (*res = clear_memory(mem_line));
		}
		free(*mem_line);
		*mem_line = mem_tmp;
	}
	if (!(tmp = ft_strdup(*mem_line)))
	{
		printf("U");
		return (*res = clear_memory(mem_line));
	}
	if (!(*mem_line = ft_substr(*mem_line, length_line(*mem_line, res), ft_len(*mem_line))))
	{
		printf("E\n");
		return (*res = clear_memory(mem_line));
	}
	free(*line);
	*line = tmp;
	return (*res);
}

int		get_next_line(int fd, char **line)
{
	static char	*mem_line;
	char		*tmp;
	int			res;
	static int z = 0;
	printf("z==%d\n", z);
	res = -1;
	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (mem_line && ft_strchr(mem_line, '\n') != 0/*&& mem_line[0] != 0 && mem_line[length_line(mem_line, &res) - 1] == '\n'*/)
	{
		z++;
		printf("z==%d\n", z);
		printf("line==%s\n", *line);
		res = get_last_n(line, &mem_line, &res);
		printf("line==%s\n", *line);
		printf("res==%d\n", res);
		if (res == 1)
			return (1);
		else if (res == -1)
			return (-1);
	}
	res = read_line(fd, line);
	z++;
	printf("z==%d\n", z);
	if (mem_line && mem_line[0] != 0 && ft_strchr(mem_line, '\n') == 0/*&& mem_line[0] != 0 && mem_line[length_line(mem_line, &res) - 1] != '\n'*/)
	{
		printf("ALLLOOOOOOOOOO?3333333");
		if (!(tmp = ft_strjoin(mem_line, *line)))
		{
			printf("O\n");
			return (res = clear_memory(&mem_line));
		}
		free(mem_line);
		printf("ALLLOOOOOOOOOO?4444444");
		mem_line = tmp;
	}
	printf("z==%d\n", z);
	res = get_last_n(line, &mem_line, &res);
	printf("z==%d\n", z);
	return (res);
}
