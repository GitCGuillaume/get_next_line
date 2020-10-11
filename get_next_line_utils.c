/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 23:36:16 by gchopin           #+#    #+#             */
/*   Updated: 2020/10/11 18:54:09 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr_char;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[j] != '\0' && s1[j] != '\n')
		j++;
	ptr_char = malloc(j + 1);
	if (ptr_char == NULL)
		return (NULL);
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		*(ptr_char + i) = s1[i];
		i++;
	}
	*(ptr_char + i) = '\0';
	return (ptr_char);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = malloc((sizeof(char const *) * ft_len((char *)s1))
			+ (sizeof(char const *) * ft_len((char *)s2)) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = (char)s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i] = (char)s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	ptr = malloc((sizeof(char) * len) + 1);
	if (ptr == NULL)
		return (NULL);
	if (ft_len(s) < start)
	{
		ptr[i] = '\0';
		return (ptr);
	}
	while (len > i && s[start] != '\0')
	{
		ptr[i] = (char)s[start];
		start++;
		i++;
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
