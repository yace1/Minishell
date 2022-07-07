/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:21:17 by dfarhi            #+#    #+#             */
/*   Updated: 2022/05/13 15:49:39 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanded.h"

t_list	*ft_lstget_index(t_list *lst, int index)
{
	int	i;

	if (index < 0)
		return (NULL);
	i = -1;
	while (lst)
	{
		if (++i == index)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
