/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:38:21 by dfarhi            #+#    #+#             */
/*   Updated: 2021/11/23 21:48:58 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	hex_format(int fd, va_list args, int maj)
{
	char	base[17];
	size_t	len;
	char	*str;

	len = 0;
	ft_strlcpy(base, "0123456789abcdef", 18);
	if (maj)
		ft_strlcpy(base, "0123456789ABCDEF", 18);
	str = ft_itoa_base((long) va_arg(args, unsigned int), base);
	if (str)
	{
		ft_putstr_fd(str, fd);
		len = ft_strlen(str);
		free(str);
	}
	return (len);
}
