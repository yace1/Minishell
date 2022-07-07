/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:12:30 by dfarhi            #+#    #+#             */
/*   Updated: 2022/01/03 15:48:06 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = ft_calloc(1, sizeof(t_list));
	if (ptr)
	{
		ptr->content = content;
		ptr->next = 0;
	}
	return (ptr);
}
