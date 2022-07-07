/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:15:37 by davifah           #+#    #+#             */
/*   Updated: 2021/10/16 13:10:15 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	long long		i;
	char			*d;
	const char		*s;

	if (!dest && !src)
		return (0);
	d = dest;
	s = src;
	if (dest > src)
	{
		i = len;
		while (--i >= 0)
			d[i] = s[i];
	}
	else
	{
		i = -1;
		while ((unsigned long)++i < len)
			d[i] = s[i];
	}
	return (dest);
}
