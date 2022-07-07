/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linkedlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:54:47 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/06/27 18:38:33 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*lst_index(t_list *lst, int index);
void	iterate_clean_lst(t_list *tmp, t_list *lst, t_list *to_free);

void	add_back_new_lst(t_list **lst)
{
	t_list	*new;

	new = ft_lstnew(NULL);
	ft_lstadd_back(lst, new);
}

//SHOULD CHECK THE LEAKS with the ft_strjoin malloc
void	add_content_last(t_list *arg, char *str, int is_malloc)
{
	arg = ft_lstlast(arg);
	if (!arg->content)
		arg->content = str;
	else
		arg->content = strjoin_free(arg->content, str, is_malloc);
}

//return 0 to avoid spending one more line when called in another function
int	free_lst(t_list *main_lst)
{
	t_list	*child;
	t_list	*child_tmp;
	t_list	*main_tmp;

	while (main_lst)
	{
		child = ((t_data *)main_lst->content)->arg_lst;
		while (child)
		{
			child_tmp = child;
			child = child->next;
			free(child_tmp->content);
			free(child_tmp);
		}
		main_tmp = main_lst;
		main_lst = main_lst->next;
		free(main_tmp->content);
		free(main_tmp);
	}
	return (0);
}

t_list	*clear_lst(t_list *lst)
{
	t_list	*tmp;
	t_list	*to_free;

	to_free = NULL;
	while (lst && lst->content == NULL)
	{	
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	tmp = lst;
	iterate_clean_lst(tmp, lst, to_free);
	return (lst);
}

t_list	*get_previous(t_list *main_lst, t_list *curr)
{
	t_list	*tmp;
	t_list	*prev;
	int		i;

	tmp = main_lst;
	prev = main_lst;
	i = 0;
	while (tmp)
	{
		if (tmp == curr && i > 0)
		{
			return (prev);
		}
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}
