/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lluitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:42:15 by dfarhi            #+#    #+#             */
/*   Updated: 2021/11/23 23:02:00 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	base_error_management(char *base);
static char	ft_llubaselen(unsigned long long nbr, char *base);

char	*ft_lluitoa_base(unsigned long long nbr, char *base)
{
	char		*str;
	int			i;
	int			mod;
	int			len;

	len = ft_llubaselen(nbr, base);
	str = ft_calloc(1 + len, sizeof(char));
	if (!str || base_error_management(base))
		return (0);
	i = 1;
	if (!nbr)
		str[0] = base[0];
	while (nbr > 0)
	{
		mod = nbr % ft_strlen(base);
		nbr /= ft_strlen(base);
		str[len - i++] = base[mod];
	}
	return (str);
}

static char	ft_llubaselen(unsigned long long nbr, char *base)
{
	int			c;

	c = 0;
	if (!nbr)
		return (1);
	while (nbr > 0)
	{
		nbr /= ft_strlen(base);
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
