/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:02:07 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/16 13:20:13 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int		get_next_line(int fd, char **line)
{
	(void)line;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;

	while (!ft_strchr(buff, '\n'))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		if (!(tmp = malloc(sizeof(char) * ft_len(buff))))
			return (-1);
		tmp = ft_strcpy(tmp, buff);
		printf("%s", tmp);
	}
	return (0);
}
