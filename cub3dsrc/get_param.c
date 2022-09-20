/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:34:13 by laballea          #+#    #+#             */
/*   Updated: 2019/12/02 13:57:40 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_res(s_param *param, char *line)
{
	int n;

	n = 0;
	if (line[n] == 'R')
	{
		n++;
		if (line[n] == ' ')
			n++;
		param->res[0] = ft_atoi(&line[n]);
		while (ft_isdigit(line[n]))
			n++;
		if (line[n] == ' ')
			n++;
		param->res[1] = ft_atoi(&line[n]);
	}
}

void	get_wall(s_param *param, char *line)
{
	int n;

	n = 0;
	if (!ft_memcmp(line, "NO ", 3) || !ft_memcmp(line, "SO ", 3)
	|| !ft_memcmp(line, "WE ", 3) || !ft_memcmp(line, "EA ", 3))
	{
		n += 3;
		if (!ft_memcmp(line, "NO", 2))
			param->NO.tx = ft_strdup(&line[n]);
		else if (!ft_memcmp(line, "SO", 2))
			param->SO.tx = ft_strdup(&line[n]);
		else if (!ft_memcmp(line, "WE", 2))
			param->WE.tx = ft_strdup(&line[n]);
		else if (!ft_memcmp(line, "EA", 2))
			param->EA.tx = ft_strdup(&line[n]);
	}
}

void	get_sprite(s_param *param, char *line)
{
	int n;

	n = 0;
	if (!ft_memcmp(line, "S ", 2))
	{
		n++;
		if (line[n] == ' ')
			n++;
		param->sprite.tx = ft_strdup(&line[n]);
	}
}

void	get_rgb_fc(s_param *param, char *line)
{
	int n;
	int j;

	n = 0;
	j = 0;
	while (line[n])
	{
		if (ft_isdigit(line[n]))
		{
			if (line[0] == 'F')
			{
				param->rgbFL[j++] = ft_atoi(&line[n]);
				n += ft_intlen(param->rgbFL[j - 1]);
			}
			if (line[0] == 'C')
			{
				param->rgbRO[j++] = ft_atoi(&line[n]);
				n += ft_intlen(param->rgbRO[j - 1]);
			}
		}
		n++;
	}
}

void	get_map(s_param *param, char *line, int read)
{
	char *tmp;

	if (line[0] == '1')
	{
		if (!param->map)
			param->map = ft_strnew(1);
		tmp = ft_strjoin_(param->map, line);
		free(param->map);
		param->map = tmp;
		if (read != 0)
		{
			if (!param->map)
				param->map = ft_strnew(1);
			tmp = ft_strjoin_(param->map, "\n");
			free(param->map);
			param->map = tmp;
		}
	}
}
