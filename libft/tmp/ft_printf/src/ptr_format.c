/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:38:06 by davifah           #+#    #+#             */
/*   Updated: 2021/11/24 14:13:22 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ptr_format(int fd, va_list args)
{
	unsigned long long	ptr;
	char				*hex;
	int					len;

	ptr = va_arg(args, unsigned long long);
	if (!ptr)
	{
		ft_putstr_fd("0x0", fd);
		return (3);
	}
	hex = ft_lluitoa_base((long long)ptr, "0123456789abcdef");
	if (hex)
	{
		ft_putstr_fd("0x", fd);
		ft_putstr_fd(hex, fd);
		len = ft_strlen(hex);
		free(hex);
		return (len + 2);
	}
	return (0);
}
