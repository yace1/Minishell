/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:16:45 by davifah           #+#    #+#             */
/*   Updated: 2021/10/16 13:07:55 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_level(const char *ptr)
{
	int	level;
	int	c;

	level = 0;
	c = -1;
	while (ft_isdigit(ptr[++c]))
		continue ;
	if (c)
		level = 1;
	while (--c > 0)
		level *= 10;
	return (level);
}

static int	ft_isspace(char c)
{
	return (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ');
}

static int	skip_chars(int *index, const char *str)
{
	while (ft_isspace(str[*index + 1]))
		*index = *index + 1;
	if (str[*index + 1] == '-')
	{
		*index = *index + 1;
		return (-1);
	}
	if (str[*index + 1] == '+')
		*index = *index + 1;
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int				negative;
	unsigned int	n;
	int				i;
	int				level;

	n = 0;
	i = -1;
	negative = skip_chars(&i, nptr);
	level = get_level(&nptr[i + 1]);
	while (ft_isdigit(nptr[++i]))
	{
		n += (nptr[i] - '0') * level;
		level /= 10;
	}
	return (n * negative);
}
