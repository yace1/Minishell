/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:47:15 by davifah           #+#    #+#             */
/*   Updated: 2021/10/16 11:13:25 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	int				d;
	char			*str1;
	char			*str2;

	if (!s1 && !s2)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	i = -1;
	while (++i < n)
	{
		d = (unsigned char)str1[i] - (unsigned char)str2[i];
		if (d != 0)
			return (d);
	}
	return (0);
}
