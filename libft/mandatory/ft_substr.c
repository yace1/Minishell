/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:59:14 by davifah           #+#    #+#             */
/*   Updated: 2021/10/28 16:14:27 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	unsigned long	c;

	c = 0;
	while (c < maxlen && s[c])
		c++;
	return (c);
}

static int	ft_findnull(const char *s, unsigned int end)
{
	unsigned int	i;

	i = -1;
	while (++i < end)
		if (!s[i])
			return (1);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	size;
	int		added;

	added = 0;
	if (ft_findnull(s, start))
		size = 0;
	else
	{
		size = ft_strnlen(&s[start], len);
		if (!s[size] && !start)
		{
			size++;
			added = 1;
		}
	}
	if (size <= len && !added)
		size++;
	ptr = ft_calloc(size, sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, &s[start], size);
	return (ptr);
}
