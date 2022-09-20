/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:53:04 by laballea          #+#    #+#             */
/*   Updated: 2019/11/25 16:30:06 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		n;

	n = 0;
	if (!(str = malloc(sizeof(char) * size)))
		return (NULL);
	while (size--)
		str[n++] = '\0';
	return (str);
}

int		ft_checkstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
			return (0);
	}
	return (1);
}

int		ft_line(char **str, char **line, int fd, int n)
{
	char	*tmp;

	if (str[fd][n] == '\n')
	{
		*line = ft_substr_(str[fd], 0, n);
		tmp = ft_strdup_(&str[fd][n + 1]);
		if (!tmp)
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
		{
			free(str[fd]);
			str[fd] = NULL;
		}
		return (1);
	}
	else if (str[fd][n] == '\0')
	{
		*line = ft_strdup_(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	return (1);
}

int		ft_gest(char **str, char **line, int fd, int readfd)
{
	int n;

	n = 0;
	if (readfd < 0)
		return (-1);
	else if (readfd == 0 && (!str[fd] || str[fd][0] == '\0'))
	{
		*line = ft_strnew(1);
		return (0);
	}
	while (str[fd][n] != '\n' && str[fd][n] != '\0')
		n++;
	return (ft_line(str, line, fd, n));
}

int		get_next_line(int fd, char **line, int BUFFER_SIZE)
{
	static char *str[1024];
	char		*buffer;
	int			readfd;
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((readfd = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[readfd] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin_(str[fd], buffer);
		free(str[fd]);
		str[fd] = tmp;
		if (!ft_check(str[fd], &buffer))
			return (-1);
		if (!ft_checkstr(str[fd]))
			break ;
	}
	if (buffer)
		free(buffer);
	return (ft_gest(str, line, fd, readfd));
}
