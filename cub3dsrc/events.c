/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:54:59 by laballea          #+#    #+#             */
/*   Updated: 2019/12/02 15:23:49 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		nowall(s_param param, int speed, double vecx, double vecy)
{
	double	posx;
	double	posy;
	double	x;
	double	y;
	int		tot;
	int		neg;
	double	i;

	neg = 1;
	i = 0;
	if (speed < 0)
		neg = -1;
	while ((int)i != speed)
	{
		x = param.pos[0];
		y = param.pos[1];
		posx = x + i * vecx;
		posy = y + i * vecy;
		tot = (int)posx + ((int)posy * param.Lmap);
		if (param.map[tot] == '1')
			return (0);
		i += neg * 0.1;
	}
	return (1);
}

int		ft_keypress(int key, s_param *param)
{
	if (key == 53)
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		ft_lstclears(&param->saveinfo);
		exit(0);
		return (-1);
	}
	if (key == 13)
		moveforward(param);
	else if (key == 1)
		movebackward(param);
	else if (key == 2)
		shiftright(param);
	else if (key == 0)
		shiftleft(param);
	else if (key == 14 || key == 12)
		rotate(key, param);
	print(param);
	return (0);
}

int		gestevent(s_param *param)
{
	mlx_hook(param->win_ptr, KeyPress, KeyPressMask, ft_keypress, param);
	return (0);
}
