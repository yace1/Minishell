/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:42:15 by dfarhi            #+#    #+#             */
/*   Updated: 2021/11/24 15:32:43 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanded.h"

static int	base_error_management(char *base);

char	*ft_itoa_base(long nbr, char *base)
{
	char		*str;
	long long	n;
	int			i;
	int			mod;

	str = ft_calloc(1 + ft_baselen(nbr, base), sizeof(char));
	if (!str || base_error_management(base))
		return (0);
	n = nbr;
	i = 1;
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	if (!n)
		str[0] = base[0];
	while (n > 0)
	{
		mod = n % ft_strlen(base);
		n /= ft_strlen(base);
		str[ft_baselen(nbr, base) - i++] = base[mod];
	}
	return (str);
}

char	ft_baselen(long nbr, char *base)
{
	long long	n;
	int			c;

	c = 0;
	n = nbr;
	if (n < 0)
	{
		n *= -1;
		c++;
	}
	if (!n)
		return (1);
	while (n > 0)
	{
		n /= ft_strlen(base);
		c++;
	}
	return (c);
}

static int	base_error_management(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (ft_strlen(base) <= 1)
		return (1);
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = -1;
		while (base[++j])
			if (base[i] == base[j] && i != j)
				return (1);
	}
	return (0);
}
