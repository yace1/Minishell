/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:23:04 by dfarhi            #+#    #+#             */
/*   Updated: 2021/11/22 16:48:12 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	ft_putlong_fd(long n, int fd)
{
	long long	level;
	int			started;

	if (n < 0)
		ft_putchar_fd('-', fd);
	started = 0;
	level = 1000000000000000000;
	while (started >= 0)
	{
		if (n / level)
			started = 1;
		if (level == 1)
			started = -1;
		if (started)
			ft_putchar_fd('0' + ft_abs(n / level), fd);
		n = n % level;
		level /= 10;
	}
}
