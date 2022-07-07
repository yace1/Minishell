/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:57:52 by davifah           #+#    #+#             */
/*   Updated: 2021/10/20 16:31:12 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nlen(int n)
{
	int	i;
	int	level;

	i = 10;
	level = 1000000000;
	if (n < 0)
		i++;
	else if (!n)
		return (1);
	while (!(n / level))
	{
		i--;
		level /= 10;
	}
	return (i);
}

static int	ft_powerten(int n)
{
	if (!n)
		return (1);
	return (10 * ft_powerten(n - 1));
}

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	int		i;
	int		level;
	int		len;
	char	*ptr;

	len = ft_nlen(n);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	level = ft_powerten(len - (n < 0) - 1);
	i = -1;
	if (n < 0)
		ptr[++i] = '-';
	while (++i < len)
	{
		ptr[i] = '0' + ft_abs(n / level);
		n = n % level;
		level /= 10;
	}
	return (ptr);
}
