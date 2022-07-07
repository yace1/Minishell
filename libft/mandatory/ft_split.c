/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:03:47 by davifah           #+#    #+#             */
/*   Updated: 2021/10/20 14:03:16 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	count_words(char const *s, char c)
{
	int	i;
	int	counter;

	counter = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c)
		{
			if (!i)
				counter++;
			else if (s[i - 1] == c)
				counter++;
		}
	}
	return (counter);
}

static char	*get_word(const char *s, char c, int *pos)
{
	int		i;
	char	*ptr;

	while (s[*pos] && s[*pos] == c)
		*pos = *pos + 1;
	i = *pos - 1;
	while (s[++i] && s[i] != c)
		continue ;
	ptr = ft_calloc(i - *pos + 1, sizeof(char));
	if (!ptr)
		return (0);
	i = -1;
	while (s[*pos + ++i] && s[*pos + i] != c)
		ptr[i] = s[*pos + i];
	*pos = *pos + i;
	return (ptr);
}

static char	**clean_tab(char **tab, int i)
{
	while (--i >= 0)
		free(tab[i]);
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		pos;
	int		len;

	len = count_words(s, c);
	tab = ft_calloc(1 + len, sizeof(char *));
	if (!tab)
		return (0);
	i = -1;
	pos = 0;
	while (++i < len)
	{
		tab[i] = get_word(s, c, &pos);
		if (!tab[i])
			return (clean_tab(tab, i));
	}
	tab[len] = 0;
	return (tab);
}
