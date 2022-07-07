/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:05:00 by dfarhi            #+#    #+#             */
/*   Updated: 2021/11/22 17:08:45 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	char_format(int fd, va_list args)
{
	ft_putchar_fd(va_arg(args, int), fd);
	return (1);
}
