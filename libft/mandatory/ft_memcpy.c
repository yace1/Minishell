/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:57:02 by davifah           #+#    #+#             */
/*   Updated: 2021/10/16 13:09:54 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	char			*d;
	const char		*s;

	if (!dest && !src)
		return (0);
	d = dest;
	s = src;
	i = -1;
	while (++i < n)
		d[i] = s[i];
	return (dest);
}
