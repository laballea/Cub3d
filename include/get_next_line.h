/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:53:56 by laballea          #+#    #+#             */
/*   Updated: 2019/11/25 16:46:16 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

int		get_next_line(int fd, char **line, int BUFFER_SIZE);
char	*ft_substr_(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup_(const char *s);
int		ft_check(char *str, char **buffer);
char	*ft_strnew(size_t size);


#endif
