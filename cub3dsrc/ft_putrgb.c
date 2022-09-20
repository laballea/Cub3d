/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:16:14 by laballea          #+#    #+#             */
/*   Updated: 2019/11/26 17:23:34 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

char	*to_str(int *nbr_final, int i, char *base)
{
	int		n;
	char	*result;

	n = 0;
	if (!(result = malloc(sizeof(char) * 3)))
		return (NULL);
	while (i--)
	{
		result[n] = base[nbr_final[i]];
		n++;
	}
	if (ft_strlen(result) == 1)
	{
		result[0] = '0';
		result[1] = result[n];
		result[2] = '\0';
	}
	return (result);
}

char	*ft_putrgb(int nbr, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	i;

	i = 0;
	size_base = 0;
	if (nbr < 0)
		nbr += 255;
	if (check_base(base))
	{
		while (base[size_base])
			size_base++;
		if (nbr == 0)
			return ("00");
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		return (to_str(nbr_final, i, base));
	}
	return (NULL);
}
