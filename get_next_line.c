/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:02:07 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/15 18:50:56 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int		get_next_line(int fd, char **line)
{
	char buff[BUFFER_SIZE + 1];
	int	nb_char;

	if (!(*line = malloc(sizeof(char *) * BUFFER_SIZE + 1)))
		return (-1);
	while ((nb_char = read(fd, buff, BUFFER_SIZE)))
	{
		buff[nb_char] = '\0';
		*line = ft_strcpy(*line, buff);
		/*if (ft_strchr(buff, '\n'))
		{
			break;
		}*/
	}
	printf("\n*line_final == %s\n", *line);
	return (0);
	}
