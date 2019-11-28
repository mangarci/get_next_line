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

int	new_line(char **s, char **line)
{
	char	*tmp;
	int	i;

	i = 0;
	tmp = ft_strdup(*s);
	ft_strfree(s);
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\n')
	{
		tmp[i] = '\0';
		*line = ft_strdup(tmp);
		*s = ft_strdup(&tmp[i + 1]);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(tmp);
		free(tmp);
	}
	return (1);
}

int	ft_read_line(int fd, char *buf)
{
	int count;

	count = read(fd, buf, BUFF_SIZE);
	if (count > 0)
		return (count);
	if (count == 0)
		return (0);
	if (count < 0)
		return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*s[4096];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int		count;
	
	if (line && fd >= 0 && BUFF_SIZE > 0 && read(fd, buf, 0) > -1)
	{
		if (s[fd] == NULL)
			s[fd] = (char*)ft_calloc(1, 1);
		while (!ft_strchr(s[fd], '\n'))
		{
			count = ft_read_line(fd, buf);
			if (count == 0)
				break;
			buf[count] = '\0';
			tmp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = ft_strdup(tmp);
			free(tmp);
		}
		if (count == 0 && s[fd][0] == '\0')
			return (0);
		return (new_line(&s[fd], line));
	}
	return (-1);
}
