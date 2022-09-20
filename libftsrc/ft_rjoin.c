/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:23:57 by laballea          #+#    #+#             */
/*   Updated: 2019/11/26 16:24:17 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_cal_bis(size_t count, size_t size)
{
	void		*tab;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(tab = malloc(size * count)))
		return (0);
	ft_bzero(tab, count * size);
	return (tab);
}

char		*ft_rjoin(char const *s1, char const *s2)
{
	char *str;
	char *ptr;

	if (!s1 || !s2 || !(str = ft_cal_bis(1, ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	ptr = str;
	while (*s2)
		*ptr++ = *s2++;
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (str);
}
