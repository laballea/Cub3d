/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:52:24 by laballea          #+#    #+#             */
/*   Updated: 2019/11/25 17:16:43 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_strlen_(const char *s)
{
	size_t	size;

	size = 0;
	while (*s++)
		size++;
	return (size);
}

char	*ft_strjoin_(char *s1, char *s2)
{
	char	*new;
	char	*memnew;

	if (!s1)
		return (0);
	if (!(new = malloc(sizeof(char) * (ft_strlen_(s1) + ft_strlen_(s2) + 1))))
		return (0);
	memnew = new;
	while (*s1)
		*new++ = *s1++;
	while (*s2)
		*new++ = *s2++;
	*new = '\0';
	return (memnew);
}

char	*ft_strdup_(const char *s)
{
	char			*cpy;
	char			*destination;
	const char		*source;
	size_t			i;
	size_t			len;

	i = 0;
	len = ft_strlen_(s);
	if (!(cpy = malloc(sizeof(char) * (len + 1))))
		return (0);
	destination = cpy;
	source = s;
	while (i < len)
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return (cpy);
}

char	*ft_substr_(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*cpy;
	char		*destination;
	const char	*source;

	i = -1;
	while (++i < start)
		s++;
	if (!(cpy = malloc(sizeof(char) * (len + 1))))
		return (0);
	destination = cpy;
	source = s;
	i = 0;
	while (i < len)
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return (cpy);
}

int		ft_check(char *str, char **buffer)
{
	if (!str)
	{
		free(*buffer);
		return (0);
	}
	return (1);
}
