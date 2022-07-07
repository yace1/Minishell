/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:05:56 by davifah           #+#    #+#             */
/*   Updated: 2021/11/24 15:51:37 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "expanded.h"

int		ft_printf(const char *format, ...);
int		ft_printf_fd(int fd, const char *format, ...);

size_t	manage_fi(int fd, va_list args, char c);
size_t	int_format(int fd, va_list args);
void	ft_putlong_fd(long n, int fd);
size_t	uint_format(int fd, va_list args);
size_t	char_format(int fd, va_list args);
size_t	str_format(int fd, va_list args);
size_t	hex_format(int fd, va_list args, int maj);
void	ft_puthex_fd(long n, int fd);
size_t	ptr_format(int fd, va_list args);
char	*ft_lluitoa_base(unsigned long long nbr, char *base);

#endif
