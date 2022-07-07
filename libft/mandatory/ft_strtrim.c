/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:28:04 by davifah           #+#    #+#             */
/*   Updated: 2021/10/20 15:56:19 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strpopulate(char const *s, size_t start, size_t end)
{
	int		i;
	char	*r;

	if (end < start)
	{
		start = 0;
		end = 0;
	}
	r = ft_calloc(end - start + 1, sizeof(char));
	if (!r)
		return (0);
	i = -1;
	while (++i + start < end)
		r[i] = s[i + start];
	return (r);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > 0 && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_strpopulate(s1, start, end));
}
