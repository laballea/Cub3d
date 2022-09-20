/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:23:34 by laballea          #+#    #+#             */
/*   Updated: 2019/12/02 16:58:15 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check(int i, int *n)
{
	int j;

	j = 0;
	while (n[j] != 0)
	{
		if (n[j] == i)
			return (1);
		j++;
	}
	return (0);
}

void	printmap(s_param *param)
{
	int n;
	int posx;
	int	posy;
	int x;
	char save;

	posx = (int)param->pos[0];
	x = -1;
	n = 1;
	posy = (int)param->pos[1];
	save = param->map[posx + (posy * param->Lmap)];
	param->map[posx + (posy * param->Lmap)] = 'P';
	while (++x < param->Lmap * param->Hmap)
	{
		if (ft_cset(param->map[x], "NSWE"))
			param->map[x] = '0';
		if (check(x, param->savehit))
			printf("\033[34;01m%c\033[00m", param->map[x]);
		else
			printf("%c", param->map[x]);
		if (n % param->Lmap == 0)
			printf("\n");
		n++;
	}
	param->map[posx + (posy * param->Lmap)] = save;
}

void	drawverline(int x, s_param *param)
{
	int		n;
	int		tin[3];
	int		tab[2];
	char	*data;

	tab[0] = 0;
	tab[1] = x * 4;
	data = mlx_get_data_addr(param->image, &tin[0], &tin[1], &tin[2]);
	param->sline = tin[1];
	param->dataimg = data;
	draw_floor(param, data, tab, tin);
	draw_wall(param ,data, tab, tin);
	draw_sky(param, data, tab, tin);
}

int		print(s_param *param)
{
	int x;
	int	w;

	x = -1;
	w = param->res[0];
	param->n = 0;
	param->image = mlx_new_image(param->mlx_ptr, param->res[0], param->res[1]);
	if (!(param->saveperpdist = malloc(sizeof(double) * param->res[0])))
		return (0);
	if (!(param->savespritepos = malloc(sizeof(double) * param->res[0])))
		return (0);
	if (!(param->savespritepos = malloc(sizeof(double*) * 2)))
		return (0);
	while (++x < param->res[0])
	{  
		init_paramcub(param, x, w);
		set_side(param);
		isitwall(param, x);
		set_draw(param);
		param->saveperpdist[x] = param->perpwalldist;
		drawverline(x, param);
		gestevent(param);
	}
	draw_sprite(param);
	free(param->saveperpdist);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->image, 0, 0);
	printmap(param);
	return (-1);
}
