/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:38:35 by laballea          #+#    #+#             */
/*   Updated: 2019/12/02 15:07:31 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_lstclears(s_sprite **lst)
{
	s_sprite	*list;
	s_sprite	*tmp;

	if (lst == NULL)
		return ;
	list = *lst;
	tmp = 0;
	while (list)
	{
		if (list->next)
			tmp = list->next;
		else
			tmp = 0;
		if (list)
			free(list);
		list = tmp;
	}
	*lst = 0;
}
