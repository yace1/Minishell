/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:09:00 by davifah           #+#    #+#             */
/*   Updated: 2021/10/16 11:15:02 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	int				d;

	i = -1;
	while (++i < n)
	{
		d = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (d != 0 || s1[i] == 0)
			return (d);
	}
	return (0);
}
