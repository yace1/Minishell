/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:12:04 by dfarhi            #+#    #+#             */
/*   Updated: 2021/11/23 21:53:31 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	uint_format(int fd, va_list args)
{
	size_t	size;
	long	n;

	size = 1;
	n = (long)va_arg(args, unsigned int);
	ft_putlong_fd(n, fd);
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}
