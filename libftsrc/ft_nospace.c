/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nospace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:42:10 by laballea          #+#    #+#             */
/*   Updated: 2019/11/27 11:53:46 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_nosmt(char *str, char c)
{
	int		n;
	int		i;
	char	*result;

	n = -1;
	i = 0;
	while (str[++n])
	{
		if (str[n] == c)
			i++;
	}
	if (!(result = malloc(sizeof(char) * (ft_strlen(str) - i))))
		return (0);
	n = -1;
	i = -1;
	while (str[++n])
	{
		if (str[n] != c)
			result[++i] = str[n];
	}
	result[++i] = '\0';
	free(str);
	return (result);
}
