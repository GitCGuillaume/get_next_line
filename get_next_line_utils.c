/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 11:51:49 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/15 18:49:35 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t    ft_len(char *str)
{
    size_t i;
    
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char            *ft_strjoin(char const *s1, char const *s2)
{
    char            *ptr;
    unsigned int    i;
    unsigned int    j;
    
    i = 0;
    j = 0;
    if (!s1 || !s2)
        return (NULL);
    if (!(ptr = malloc((sizeof(char const *) * ft_len((char *)s1))
                       + (sizeof(char const *) * ft_len((char *)s2)) + 1)))
        return (NULL);
    while (s1[i] != '\0')
    {
        ptr[i] = (char)s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        ptr[i] = (char)s2[j];
        i++;
        j++;
    }
    ptr[i] = '\0';
    return (ptr);
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
