/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:54:01 by dfarhi            #+#    #+#             */
/*   Updated: 2021/10/25 12:13:40 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		i;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	i = -1;
	while ((unsigned int)++i < size * count)
		*(char *)(ptr + i) = 0;
	return (ptr);
}
