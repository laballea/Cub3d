/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_to_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laballea <laballea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:54:36 by laballea          #+#    #+#             */
/*   Updated: 2019/11/26 16:03:07 by laballea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int n, int i)
{
	if (i == 1)
		return (n);
	else if (i == 0)
		return (1);
	else
		return (n * ft_power(n, i - 1));
}

int		get_pos(char *base, char c)
{
	int i;
	int n;

	i = -1;
	n = 0;
	while (base[++i])
	{
		if (base[i] == c)
			return (n);
		n++;
	}
	return (0);
}

int		ft_hexa_to_dec(char *nbr)
{
	int			n;
	int			i;
	int			result;
	const char	*hexa = "0123456789ABCDEF";

	n = 0;
	i = 0;
	result = 0;
	while (nbr[n])
		n++;
	n--;
	while (n > -1)
	{
		result += get_pos((char *)hexa, nbr[n]) * ft_power(16, i);
		i++;
		n--;
	}
	return (result);
}
