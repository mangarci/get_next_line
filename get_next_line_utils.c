/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:11:25 by mangarci          #+#    #+#             */
/*   Updated: 2019/11/27 13:16:10 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = (char*)malloc(sizeof(*dst) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (*s1 != '\0')
		dst[i++] = *s1++;
	while (*s2 != '\0')
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char*)s;
	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (len + 1))) || !s)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start] && i < len)
		{
			str[i] = s[start];
			start++;
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*aux;

	i = 0;
	aux = (char*)s;
	while (aux[i])
	{
		if (aux[i] == c)
			return (&aux[i]);
		i++;
	}
	if (aux[i] == '\0' && c == '\0')
		return (&aux[i]);
	return (NULL);
}
