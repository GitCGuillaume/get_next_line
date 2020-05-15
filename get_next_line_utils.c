/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 11:51:49 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/15 13:49:27 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, char *src, int i)
{
	unsigned int j;

	j = 0;
	while (src[i + j] != '\n' && src[i + j] != '\0' && BUFFER_SIZE > j)
	{
		dest[j] = src[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
