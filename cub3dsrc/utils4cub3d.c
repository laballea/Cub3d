/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:30:26 by laballea          #+#    #+#             */
/*   Updated: 2019/12/02 17:34:06 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_paramcub(s_param *param, int x, int w)
{
	param->camx = 2 * x / (double)w - 1;
	param->raydirx = param->dir[0] + param->planex * param->camx;
	param->raydiry = param->dir[1] + param->planey * param->camx;
	param->mapx = (int)param->pos[0];
	param->mapy = (int)param->pos[1];
	param->deltadistx = fabs(1 / param->raydirx);
	param->deltadisty = fabs(1 / param->raydiry);
	param->hit = 0;
}

void	set_side(s_param *param)
{
	if (param->raydirx < 0)
	{
		param->stepx = -1;
		param->sidedistx = (param->pos[0] - param->mapx) * param->deltadistx;
	}
	else
	{
		param->stepx = 1;
		param->sidedistx = (param->mapx + 1.0 - param->pos[0])
		* param->deltadistx;
	}
	if (param->raydiry < 0)
	{
		param->stepy = -1;
		param->sidedisty = (param->pos[1] - param->mapy)
		* param->deltadisty;
	}
	else
	{
		param->stepy = 1;
		param->sidedisty = (param->mapy + 1.0 - param->pos[1])
		* param->deltadisty;
	}
}

void	savelst(s_param *param)
{
	if (param->savelst != param->mapx + (param->mapy * param->Lmap))
	{
		param->info->posx = param->mapx + 0.5;
		param->info->posy = param->mapy + 0.5;
		param->info->perpwalldist = param->perpwalldist;
		param->info->next = ft_lstnews();
		param->info = param->info->next;
		param->info->next = 0;
		param->save = param->mapx + (param->mapy * param->Lmap);
	}
	param->savelst = param->mapx + (param->mapy * param->Lmap);
}

void	savehit(s_param *param)
{
	if (param->save != param->mapx + (param->mapy * param->Lmap))
	{
		param->savehit[param->n] = param->mapx + (param->mapy * param->Lmap);
		param->n++;
		param->savehit[param->n] = 0;
	}
	param->save = param->mapx + (param->mapy * param->Lmap);
}

void	isitwall(s_param *param, int x)
{
	while (param->hit == 0)
	{
		if (param->sidedistx < param->sidedisty)
		{
			param->sidedistx += param->deltadistx;
			param->mapx += param->stepx;
			param->side = 0;
		}
		else
		{
			param->sidedisty += param->deltadisty;
			param->mapy += param->stepy;
			param->side = 1;
		}
		if (param->map[param->mapx + (param->mapy * param->Lmap)] == '2')
			savelst(param);
		if (param->map[param->mapx + (param->mapy * param->Lmap)] == '1')
		{
			savehit(param);
			param->hit = 1;
		}
	}
}

void	set_draw(s_param *param)
{
	if (param->side == 0)
		param->perpwalldist = (param->mapx - param->pos[0]
		+ (1 - param->stepx) / 2) / param->raydirx;
	else
		param->perpwalldist = (param->mapy - param->pos[1]
		+ (1 - param->stepy) / 2) / param->raydiry;
	param->lineheight = (int)(param->res[1] / param->perpwalldist);
	param->drawstart = -param->lineheight / 2 + param->res[1] / 2;
	param->drawend = param->lineheight / 2 + param->res[1] / 2;
	if (param->drawstart < 0)
		param->drawstart = 0;
	if (param->drawend >= param->res[1])
		param->drawend = param->res[1] - 1;
}
