/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:18:47 by dfarhi            #+#    #+#             */
/*   Updated: 2021/10/21 14:47:59 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	add_element(t_list **lst2, t_list *item, void *(*f)(void *))
{
	t_list	*new;
	void	*new_content;

	new_content = (*f)(item->content);
	new = ft_lstnew(new_content);
	if (!new_content || !new)
		return (0);
	if (!lst2)
		*lst2 = new;
	else
		ft_lstadd_back(lst2, new);
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*loop;
	t_list	*lst2;

	lst2 = 0;
	loop = lst;
	while (loop)
	{
		if (!add_element(&lst2, loop, (*f)))
		{
			ft_lstclear(&lst2, (*del));
			return (0);
		}
		loop = loop->next;
	}
	return (lst2);
}
