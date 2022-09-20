/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawimg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:28:19 by laballea          #+#    #+#             */
/*   Updated: 2019/12/02 18:01:54 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor(s_param *param, char *data, int *tab, int *tin)
{
	int n;

	while (tab[0] < param->drawstart * tin[1])
	{
		data[(tab[1] + tab[0] + 2)] = (signed char)param->rgbRO[0];
		data[(tab[1] + tab[0] + 1)] = (signed char)param->rgbRO[1];
		data[tab[1] + tab[0]] = (signed char)param->rgbRO[2];
		tab[0] += tin[1];
	}
}

void	draw_sky(s_param *param, char *data, int *tab, int *tin)
{
	int n;

	while (tab[0] < param->res[1] * tin[1])
	{
		data[(tab[1] + tab[0] + 2)] = (signed char)param->rgbFL[0];
		data[(tab[1] + tab[0] + 1)] = (signed char)param->rgbFL[1];
		data[(tab[1] + tab[0])] = (signed char)param->rgbFL[2];
		tab[0] += tin[1];
	}
}

void	draw_wall(s_param *param, char *data, int *tab, int *tin)
{
	int		n;
	int		imgy;
	double	wallx;
	int		texx;
	double wally;
	s_img image;
	

	if (param->side == 0)
	{
		if (param->raydirx < 0)
			image = param->EA;
		else
			image = param->WE;
		wallx = param->pos[1] + param->perpwalldist * param->raydiry;
	}
	else
	{
		if (param->raydiry < 0)
			image = param->SO;
		else
			image = param->NO;
		wallx = param->pos[0] + param->perpwalldist * param->raydirx;
	}
	wallx -= floor((wallx));
	texx = (int)(wallx * (double)image.w);
	if(param->side == 0 && param->raydirx > 0)
		texx = image.w - texx - 1;
	if(param->side == 1 && param->raydiry < 0)
		texx = image.w - texx - 1;
	while (tab[0] < param->drawend * tin[1])
	{
		n = 0;
		imgy = image.sline * ((tab[0] / tin[1] - param->drawstart) * image.h / (param->drawend - param->drawstart));
		data[(tab[1] + tab[0] + 2)] = image.data[(texx * 4) + (imgy) + 2];
		data[(tab[1] + tab[0] + 1)] = image.data[(texx * 4) + (imgy) + 1];
		data[(tab[1] + tab[0])] = image.data[(texx * 4) + (imgy)];
		tab[0] += tin[1];
	}
}

void	draw_sprite(s_param *param)
{
	int		n;
	int		imgy;
	double	wallx;
	int		texx;
	double	wally;
	s_img	image;
	int		i;
	int stripe;
	int y;
	
	i = -1;
	image = param->sprite;
	while (++i < ft_lstsizes(param->saveinfo))
	{
		double spritex = get_pos_lst(param->saveinfo, 'x', i) - param->pos[0];
		double spritey = get_pos_lst(param->saveinfo, 'y', i) - param->pos[1];

		double invdet = 1.0 / (param->planex * param->dir[1] - param->dir[0] * param->planey);

		double transformx = invdet * (param->dir[1] * spritex - param->dir[0] * spritey);
		double transformy = invdet * (-param->planey * spritex + param->planex * spritey);

		int spritescreenx = (int)((param->res[0] / 2) * (1 + transformx / transformy));
		int spriteheight = abs((int)(param->res[1] / (transformy)));
		int drawstarty = -spriteheight / 2 + param->res[1] / 2;
		if(drawstarty < 0)
			drawstarty = 0;
		int drawendy = spriteheight / 2 + param->res[1] / 2;
		if(drawendy >= param->res[1])
			drawendy = param->res[1] - 1;
		int spritewidth = abs((int)(param->res[1] / (transformy)));
		int drawstartx = -spritewidth / 2 + spritescreenx;
		if(drawstartx < 0)
			drawstartx = 0;
		int drawendx = spritewidth / 2 + spritescreenx;
		if(drawendx >= param->res[0])
			drawendx = param->res[0] - 1;
		stripe = drawstartx - 1;
		while (++stripe < drawendx)
		{
			y = drawstarty - 1;
			int texx = (int)((stripe - (-spritewidth / 2 + spritescreenx)) * param->sprite.w / spritewidth);
			if (transformy > 0 && stripe > 0 && stripe < param->res[0] && transformy < param->saveperpdist[stripe])
			{
				while (++y < drawendy)
				{
					int d = y * 256 - param->res[1] * 128 + spriteheight * 128;
					int texy = ((d * param->sprite.h) / spriteheight) / 256;
					if (image.data[texy * param->sprite.sline + texx * 4 + 0] >= 30 || image.data[texy * param->sprite.sline + texx * 4 + 1] >= 30 || image.data[texy * param->sprite.sline + texx * 4 + 2] >= 30)
					{
						param->dataimg[stripe * 4 + y * param->sline + 2] = image.data[texy * param->sprite.sline + texx * 4 + 2];
						param->dataimg[stripe * 4 + y * param->sline + 1] = image.data[texy * param->sprite.sline + texx * 4 + 1];
						param->dataimg[stripe * 4 + y * param->sline] = image.data[texy * param->sprite.sline + texx * 4];
					}
				}
			}
		}
	}
}