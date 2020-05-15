/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:02:07 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/15 13:51:06 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	static char buff[BUFFER_SIZE + 1];
	static int	nb_char;
	int i;

	i = 0;
	//Peut etre trop de mémoire si 10000000
	if (!(*line = malloc(sizeof(char *) * BUFFER_SIZE + 1)))
		return (-1);
	while ((nb_char = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[nb_char] = '\0';
		printf("nb_char == %d", nb_char);
		*line = ft_strncpy(*line, buff, i);
		printf("%s", *line);
		//while (buff[i + j] != '\n' && nb_char > i + j)
		//{
			//printf("j == %d\n", j);
			//printf("i+j == %d\n", i+j);
		//	*line = &buff[i + j];
			//printf("line[j] == %c", *line[j]);
		//	j++;
		//}
		i++;
	}
	printf("\n*line_final == %s\n", *line);
	/*printf("\n*line_final == %c\n", *line[1]);
	printf("\n*line_final == %c\n", *line[2]);
	printf("\n*line_final == %c\n", *line[3]);
	printf("\n*line_final == %c\n", *line[4]);
	printf("\n*line_final == %c\n", *line[5]);
	printf("\n*line_final == %c\n", *line[6]);
	printf("\n*line_final == %c\n", *line[7]);
	printf("\n*line_final == %c\n", *line[8]);
	printf("\n*line_final == %c\n", *line[9]);
	printf("\n*line_final == %c\n", *line[10]);
	printf("\n*line_final == %c\n", *line[11]);
	printf("\n*line_final == %c\n", *line[12]);
	printf("\n*line_final == %c\n", *line[13]);
	printf("\n*line_final == %c\n", *line[14]);
	printf("\n*line_final == %c\n", *line[15]);
	printf("\n*line_final == %c\n", *line[16]);
	printf("\n*line_final == %c\n", *line[17]);
	printf("\n*line_final == %c\n", *line[18]);
	printf("\n*line_final == %c\n", *line[19]);
	printf("\n*line_final == %c\n", *line[20]);
	*/
	return (0);
	}
