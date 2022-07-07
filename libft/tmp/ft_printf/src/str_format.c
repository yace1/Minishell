/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:10:00 by dfarhi            #+#    #+#             */
/*   Updated: 2021/11/23 01:16:33 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define NULL_MESSAGE "(null)"

size_t	str_format(int fd, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd(NULL_MESSAGE, fd);
		return (ft_strlen(NULL_MESSAGE));
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
