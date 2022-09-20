/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:05:17 by laballea          #+#    #+#             */
/*   Updated: 2019/12/02 14:52:35 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

s_sprite	*ft_lstnews(void)
{
	s_sprite *list;

	if (!(list = malloc(sizeof(s_sprite))))
		return (0);
	list->next = 0;
	return (list);
}
