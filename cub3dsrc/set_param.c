/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:43:11 by laballea          #+#    #+#             */
/*   Updated: 2019/11/29 13:17:33 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_dirwe(s_param *param, char c)
{
	if (c == 'W')
	{
		param->dir[0] = -1;
		param->dir[1] = 0;
		param->planex = 0;
		param->planey = 0.66;
	}
	else if (c == 'E')
	{
		param->dir[0] = 1;
		param->dir[1] = 0;
		param->planex = 0;
		param->planey = -0.66;
	}
}

void	get_dirns(s_param *param, char c)
{
	if (c == 'N')
	{
		param->dir[0] = 0;
		param->dir[1] = -1;
		param->planex = -0.66;
		param->planey = 0;
	}
	else if (c == 'S')
	{
		param->dir[0] = 0;
		param->dir[1] = 1;
		param->planex = 0.66;
		param->planey = 0;
	}
	get_dirwe(param, c);
}

void	set_pos(s_param *param)
{
	int tin[3];

	tin[0] = -1;
	tin[2] = 0;
	tin[1] = 0;
	while (param->map[++tin[0]])
	{
		if (ft_cset(param->map[tin[0]], "NESW"))
		{
			param->pos[0] = tin[1] % param->Lmap + 0.5;
			param->pos[1] = tin[1] / param->Lmap + 0.5;
			get_dirns(param, param->map[tin[0]]);
		}
		if (param->map[tin[0]] != '\n')
			tin[1]++;
		else
		{
			if (tin[2] == 0)
				param->Lmap = tin[0];
			tin[2] = 1;
		}
	}
	param->map = ft_nosmt(param->map, '\n');
	param->Hmap = tin[1] / param->Lmap;
}
