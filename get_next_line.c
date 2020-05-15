/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:02:07 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/15 21:05:53 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int		get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;

	if (!(*line = malloc(sizeof(char *) * BUFFER_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		printf("nb_char == %d", ret);
		printf("%s", ft_strjoin(*line, buff));
		if (ft_strchr(buff, '\n'))
		{
			buff[ret] = '\0';
			printf("break");
			break;
		}
		printf("size == %zu\n", ft_len(buff));
	}
	return (0);
	}
