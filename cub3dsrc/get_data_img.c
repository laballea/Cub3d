/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:39:33 by laballea          #+#    #+#             */
/*   Updated: 2019/12/02 17:41:44 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_data_img(s_param *param, s_img *img)
{
	int		bit;
	int		sline;
	int		endian;
	void	*image_ptr;
	char	*result;

	image_ptr = mlx_xpm_file_to_image(param->mlx_ptr,
	img->tx, &img->w, &img->h);
	img->image = image_ptr;
	img->data = (unsigned char*)mlx_get_data_addr(image_ptr, &bit, &img->sline, &endian);
}
