/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 11:51:49 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/15 14:41:28 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src, int i)
{
	unsigned int j;

	j = 0;
	while (src[i + j] != '\n' && src[i + j] != '\0')
	{
		dest[j] = src[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char	*located_c;
	int		i;

	located_c = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (located_c[i] == c)
		{
			return (&located_c[i]);
		}
		i++;
	}
	if (located_c[i] == c)
		return (&located_c[i]);
	return (0);
}
