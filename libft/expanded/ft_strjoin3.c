/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:06:57 by davifah           #+#    #+#             */
/*   Updated: 2022/05/27 14:22:19 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanded.h"

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;
	size_t	len3;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	ptr = ft_calloc(len1 + len2 + len3 + 1, sizeof(char));
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s1, len1);
	ft_memcpy(&ptr[len1], s2, len2);
	ft_memcpy(&ptr[len1 + len2], s3, len3);
	ptr[len1 + len2 + len3] = 0;
	return (ptr);
}
