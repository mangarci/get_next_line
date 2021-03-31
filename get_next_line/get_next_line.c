/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:58:19 by mangarci          #+#    #+#             */
/*   Updated: 2019/12/03 16:25:19 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	unsigned char		*str;
	size_t				i;

	str = (unsigned char*)s;
	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_return(int len, char **line)
{
	if (len < 0)
		return (-1);
	*line = ft_strdup("");
	return (0);
}

char		*ft_get_line(char *s, char **line, int *len)
{
	char	*aux;
	int		pos;

	pos = 0;
	while (s[pos] != '\n' && s[pos] != '\0')
		pos++;
	if (s[pos] == '\n')
	{
		*line = ft_substr(s, 0, pos);
		aux = ft_strdup(s + (pos + 1));
		free(s);
		s = aux;
		if (s[0] == '\0')
			s = ft_del(s);
		*len = 1;
	}
	else
	{
		*line = ft_strdup(s);
		free(s);
		s = NULL;
		*len = 0;
	}
	return (s);
}

int			get_next_line(int fd, char **line)
{
	static char	*s[4096];
	int			len;
	char		buff[BUFF_SIZE + 1];
	char		*aux;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while ((len = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[len] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			aux = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = aux;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if ((len < 0) || (len == 0 && s[fd] == '\0'))
		return (ft_return(len, line));
	s[fd] = ft_get_line(s[fd], line, &len);
	return (len);
}
