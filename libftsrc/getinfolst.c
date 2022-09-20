/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfolst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:29:03 by laballea          #+#    #+#             */
/*   Updated: 2019/12/02 17:32:23 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		get_pos_lst(s_sprite *lst, char c, int i)
{
	int n;

	n = -1;
	if (i == 0 || lst == NULL)
		return (0);
	while (++n < i - 1)
		lst = lst->next;
	if (c == 'x')
		return (lst->posx);
	if (c == 'y')
		return (lst->posy);
	return (0);
}