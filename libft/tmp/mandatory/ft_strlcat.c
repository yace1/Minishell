/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:00:11 by davifah           #+#    #+#             */
/*   Updated: 2022/05/10 15:46:35 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t size)
{
	size_t	len;

	len = -1;
	while (++len < size && s[len])
		continue ;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen((char *)src);
	dstlen = ft_strnlen(dst, size);
	if (dstlen == size)
		return (size + srclen);
	if (srclen < size - dstlen)
	{
		ft_memcpy(&dst[dstlen], (char *)src, srclen);
		dst[dstlen + srclen] = 0;
	}
	else
	{
		ft_memcpy(&dst[dstlen], (char *)src, size - dstlen - 1);
		dst[dstlen + size - 1] = 0;
	}
	return (dstlen + srclen);
}
