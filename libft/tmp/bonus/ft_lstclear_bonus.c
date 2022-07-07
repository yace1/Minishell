/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:04:13 by dfarhi            #+#    #+#             */
/*   Updated: 2021/10/21 12:10:59 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	rec_lstclear(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		if (lst->next)
			rec_lstclear(lst->next, (*del));
		ft_lstdelone(lst, (*del));
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst)
	{
		rec_lstclear(*lst, (*del));
		*lst = 0;
	}
}
