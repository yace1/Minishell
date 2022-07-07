/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:42:21 by davifah           #+#    #+#             */
/*   Updated: 2021/10/20 10:58:07 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	level;
	int		started;

	if (n < 0)
		ft_putchar_fd('-', fd);
	started = 0;
	level = 1000000000;
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
