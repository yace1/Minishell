/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:59:47 by davifah           #+#    #+#             */
/*   Updated: 2021/10/16 14:44:09 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reset(size_t *i, size_t *k, long long *res)
{
	*i = *res;
	*k = 0;
	*res = -1;
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		k;
	long long	res;

	if (!big && !little)
		return (0);
	i = -1;
	k = 0;
	res = -1;
	if (!*little)
		return ((char *)big);
	while (++i < len && big[i])
	{
		if (big[i] == little[k])
		{
			if (res < 0)
				res = i;
			if (k++ == ft_strlen(little) - 1)
				return ((char *)&big[res]);
		}
		else if (res >= 0)
			reset(&i, &k, &res);
	}
	return (0);
}
