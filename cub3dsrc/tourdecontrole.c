/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tourdecontrole.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:38:48 by laballea          #+#    #+#             */
/*   Updated: 2019/11/29 13:18:59 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_param(s_param *param)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*mem;
	int		read;

	fd = open("map.cub", O_RDONLY);
	param->map = ft_strnew(1);
	while ((read = get_next_line(fd, &line, 1)) > -1)
	{
		get_res(param, line);
		get_wall(param, line);
		get_sprite(param, line);
		get_rgb_fc(param, line);
		get_map(param, line, read);
		free(line);
		if (read == 0)
			break ;
	}
	param->map = ft_nosmt(param->map, ' ');
	set_pos(param);
}
