/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:59:14 by dfarhi            #+#    #+#             */
/*   Updated: 2021/11/23 02:23:24 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	int_length(int nbr);

size_t	int_format(int fd, va_list args)
{
	int	n;

	n = va_arg(args, int);
	ft_putnbr_fd(n, fd);
	return (int_length(n));
}

static size_t	int_length(int nbr)
{
	size_t	size;
	int		level;
	int		started;
	long	n;

	size = 0;
	level = 1000000000;
	started = 0;
	n = nbr;
	if (n < 0)
		n *= -1 * ++size;
	while (started >= 0)
	{
		if (n / level)
			started = 1;
		if (level == 1)
			started = -1;
		if (started)
			size++;
		n = n % level;
		level /= 10;
	}
	return (size);
}
