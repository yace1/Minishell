/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:31:27 by dfarhi            #+#    #+#             */
/*   Updated: 2021/11/23 01:48:05 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	manage_fi(int fd, va_list args, char c)
{
	if (c == 'd' || c == 'i')
		return (int_format(fd, args));
	else if (c == 'u')
		return (uint_format(fd, args));
	else if (c == 'c')
		return (char_format(fd, args));
	else if (c == 's')
		return (str_format(fd, args));
	else if (c == 'x')
		return (hex_format(fd, args, 0));
	else if (c == 'X')
		return (hex_format(fd, args, 1));
	else if (c == 'p')
		return (ptr_format(fd, args));
	return (1);
}
