/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:02:15 by davifah           #+#    #+#             */
/*   Updated: 2022/06/15 14:55:39 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanded.h"

t_list	*ft_lstremove_index(t_list **lst, int index)
{
	t_list	*item;
	t_list	*temp;

	if (index < 0 || index >= ft_lstsize(*lst))
		return (0);
	item = *lst;
	if (!index)
	{
		temp = item;
		*lst = item->next;
	}
	while (index > 0)
	{
		if (!item)
			return (0);
		if (index == 1)
		{
			temp = item->next;
			item->next = temp->next;
		}
		item = item->next;
		index--;
	}
	temp->next = 0;
	return (temp);
}
