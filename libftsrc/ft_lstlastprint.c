/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlastprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:05:02 by laballea          #+#    #+#             */
/*   Updated: 2019/12/02 17:31:34 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

s_sprite		*ft_lstlastprint(s_sprite *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next != 0)
	{
		printf("%f %f %f\n", lst->posx, lst->posy, lst->perpwalldist);
		lst = lst->next;
	}
	return (lst);
}
