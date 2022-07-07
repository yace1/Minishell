/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 00:07:09 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/06/27 17:36:08 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_quote_error(char *error, t_list *lst, t_list *env);
int	check_after_redir(t_list *temp_second, t_list *lst, t_list *env);

int	redir_is_alone(t_list *lst, t_list *env)
{
	t_list	*tmp_main;
	t_list	*temp_second;

	tmp_main = lst;
	while (tmp_main)
	{
		if (tmp_main->content)
			temp_second = ((t_data *)tmp_main->content)->arg_lst;
		else
			return (0);
		while (temp_second)
		{
			if (!check_after_redir(temp_second, lst, env))
				return (0);
			temp_second = temp_second->next;
		}
		tmp_main = tmp_main->next;
	}
	return (1);
}

int	check_after_redir(t_list *temp_second, t_list *lst, t_list *env)
{
	if (!temp_second->next && get_redir_type(temp_second->content))
		return (print_quote_error("newline", lst, env));
	else if (get_redir_type(temp_second->content) && temp_second->next)
	{
		if (temp_second->next->next
			&& get_redir_type(temp_second->next->content))
		{
			if (get_redir_type(temp_second->next->next->content))
				return (print_quote_error(
						(char *)temp_second->next->next->content, lst, env));
		}
		if (*(char *)temp_second->next->content == 0)
			return (print_quote_error("|", lst, env));
	}
	return (1);
}

int	print_quote_error(char *error, t_list *lst, t_list *env)
{
	char	*str;

	str = ft_strjoin3("minishell: syntax error near unexpected token `",
			error, "'\n");
	ft_putstr_fd(str, 2);
	free(str);
	free_lst(lst);
	set_exit_status(&env, 2);
	return (0);
}

int	quote_error_nb(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == 39)
		{
			i = skip_quote(str, 39, i);
			if (i == -1)
				return (0);
		}
		else if (str[i] == '"')
		{
			i = skip_quote(str, '"', i);
			if (i == -1)
				return (0);
		}
		i++;
	}
	return (1);
}
