/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:16:19 by mangarci          #+#    #+#             */
/*   Updated: 2019/11/27 14:29:18 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	int		i;

	i = 0;
	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	while (i < count * size)
	{
		((char*)str)[i] = 0;
		i++;
	}
	return (str);
}

void	ft_strfree(char *s)
{
	if (s)
	{
		free((char*)s);
		*s = '\0';
	}
	return ;
}

int		ft_line(char **s, char **line, int fd, int ret)
{
	int		len;
	char	*tmp;

	len = 0;
	while (s[fd][len] != '\n' || s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_substr(s[fd], 0, len);
		tmp = ft_strdup(s[fd]);
		ft_strfree(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strfree(s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strfree(s[fd]);
	}
	return (1);
}

int		get_next_line(int fd,char **line)
{
	static char		*s[4096];
	char			*buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = NULL;
		if (s[fd] == NULL)
			s[fd] = ft_calloc(1, 1);
		tmp = ft_strjoin(s[fd], *buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(*buf, '\n'))
			break;
	}
	if (ret < -1)
		return (-1);
	if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_line(s, line, fd, ret));
}
