/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:36:02 by mangarci          #+#    #+#             */
/*   Updated: 2019/11/27 14:29:35 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

int			get_next_line(int fd, char **line);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		ft_strlen(const char *s);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);

#endif
