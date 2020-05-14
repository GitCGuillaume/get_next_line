/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:02:07 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/14 20:06:42 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	(void)line;
	int	nb_char;
	char buff[BUFFER_SIZE + 1];
	while ((nb_char = read(fd, buff, BUFFER_SIZE)))
	{
		buff[nb_char] = '\0';
		printf("nb_char == %d\n", nb_char);
		printf("*line == %s\n", buff);
	}
	printf("*line == %s\n", buff);
	printf("nb_char == %d", nb_char);
	return (0);
}
