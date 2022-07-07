/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:36:50 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/06/27 18:10:52 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*s_quote_filling(char *str, t_list *arg);

char	*fill_s_quote(t_list *arg, char *str, t_list **lst, t_list *env)
{
	int		i;

	(void)env;
	if (*str == 39)
	{
		i = 0;
		str++;
		arg = ft_lstlast(arg);
		while (str[i] != 39 && str[i] != 0)
			i++;
		i = 0;
		str = s_quote_filling(str, arg);
		str++;
		str = skip_space(str, 0);
		if (ft_isspace(*str))
			add_back_new_lst(lst);
	}
	return (str);
}

static char	*s_quote_filling(char *str, t_list *arg)
{
	char	*c;

	while (*str != 39 && *str != 0)
	{
		c = ft_calloc(2, sizeof(char));
		if (*str != 39)
		{
			c[0] = *str;
			c[1] = 0;
			add_content_last(arg, c, 1);
			str++;
		}
		else
			free(c);
	}
	return (str);
}

void	print_linked_lst(t_list *lst)
{
	t_list	*tmp_main;
	t_list	*temp_second;
	int		i;

	i = 1;
	tmp_main = lst;
	while (tmp_main)
	{
		if (tmp_main->content)
			temp_second = ((t_data *)tmp_main->content)->arg_lst;
		else
			return ((void)0);
		printf("--pipe nb %d--\n", i);
		while (temp_second)
		{
			printf("->%s<-\n", (char *)temp_second->content);
			temp_second = temp_second->next;
		}
		printf("\n");
		tmp_main = tmp_main->next;
		i++;
	}
}

void	iterate_clean_lst(t_list *tmp, t_list *lst, t_list *to_free)
{
	while (tmp)
	{
		if (!tmp->next)
			break ;
		if ((char *)tmp->content == NULL && get_previous(lst, tmp))
		{			
			get_previous(lst, tmp)->next = tmp->next;
			to_free = tmp;
			tmp = get_previous(lst, tmp);
			free (to_free);
		}
		else
		{
			while (tmp->next && tmp->next->content == NULL)
			{
				to_free = tmp->next;
				tmp->next = tmp->next->next;
				free(to_free);
			}
		}
		tmp = tmp->next;
	}
}

int	check_nxt_char(char *str)
{
	if (!((str[arg_size(str) - 1] == '=' && (str[arg_size(str)] == '"'
					|| str[arg_size(str)] == '$' || str[arg_size(str)] == 39))
			|| !(str[arg_size(str) - 1] == '$'))
		|| ft_isspace(str[arg_size(str)]))
		return (1);
	return (0);
}
