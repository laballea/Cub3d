/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:57:22 by laballea          #+#    #+#             */
/*   Updated: 2019/12/02 10:18:20 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		moveforward(s_param *param)
{
	double dirx;
	double diry;
	double speed;

	dirx = param->dir[0] * param->movespeed;
	diry = param->dir[1] * param->movespeed;
	speed = param->movespeed;
	if (nowall(*param, speed + 1.5, dirx, diry))
	{
		param->pos[0] += speed * dirx;
		param->pos[1] += speed * diry;
	}
	return (0);
}

int		movebackward(s_param *param)
{
	double dirx;
	double diry;
	double speed;

	speed = param->movespeed;
	dirx = param->dir[0] * param->movespeed;
	diry = param->dir[1] * param->movespeed;
	if (nowall(*param, -(speed + 1.5), dirx, diry))
	{
		param->pos[0] -= speed * dirx;
		param->pos[1] -= speed * diry;
	}
	return (0);
}

int		shiftright(s_param *param)
{
	double dirx;
	double diry;
	double speed;

	speed = param->movespeed;
	dirx = param->planex * param->movespeed;
	diry = param->planey * param->movespeed;
	if (nowall(*param, speed + 1.5, dirx, diry))
	{
		param->pos[0] += speed * dirx;
		param->pos[1] += speed * diry;
	}
	return (0);
}

int		shiftleft(s_param *param)
{
	double dirx;
	double diry;
	double speed;

	speed = param->movespeed;
	dirx = param->planex * param->movespeed;
	diry = param->planey * param->movespeed;
	if (nowall(*param, -(speed + 1.5), dirx, diry))
	{
		param->pos[0] -= speed * dirx;
		param->pos[1] -= speed * diry;
	}
	return (0);
}

int		rotate(int key, s_param *param)
{
	double rotspeed;
	double olddirx;
	double oldplanex;

	rotspeed = param->rotspeed;
	if (key == 14)
		rotspeed *= -1;
	olddirx = param->dir[0];
	param->dir[0] = param->dir[0] * cos(rotspeed)
	- param->dir[1] * sin(rotspeed);
	param->dir[1] = olddirx * sin(rotspeed)
	+ param->dir[1] * cos(rotspeed);
	oldplanex = param->planex;
	param->planex = param->planex * cos(rotspeed)
	- param->planey * sin(rotspeed);
	param->planey = oldplanex * sin(rotspeed)
	+ param->planey * cos(rotspeed);
	return (0);
}
