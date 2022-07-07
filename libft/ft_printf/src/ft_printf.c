/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:55:37 by davifah           #+#    #+#             */
/*   Updated: 2022/05/01 23:28:30 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*loop_format(const char *format);

static int	print_format(int fd, const char *format, va_list args)
{
	size_t	i;
	size_t	size;
	int		last_per;

	i = -1;
	size = 0;
	last_per = 0;
	while (format[++i])
	{
		if (i && &format[i] == loop_format(&format[i - 1]) && last_per)
			size += manage_fi(fd, args, format[i]);
		else if (&format[i] < (loop_format(&format[i]) - 1) && !last_per)
		{
			ft_putchar_fd(format[i], fd);
			size++;
		}
		if (format[i] != '%' || last_per)
			last_per = 0;
		else
			last_per = 1;
	}
	va_end(args);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	return (print_format(1, format, args));
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	return (print_format(fd, format, args));
}

static char	*loop_format(const char *format)
{
	size_t	i;

	i = -1;
	while (format[++i])
		if (i && format[i - 1] == '%' && format[i] != '%'
			&& ft_strchr("cspdiuxX", format[i]))
			return ((char *)&format[i]);
	return (0);
}
