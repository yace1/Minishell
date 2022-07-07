/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_info_cmdargs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:28:24 by dfarhi            #+#    #+#             */
/*   Updated: 2022/05/23 17:30:29 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	add_cmd_arg(t_list **cmd_args, char *content);
static char	**cmd_args_ll2list(t_list *cmd_args);
static void	del_function_void(void *content);

int	get_cmdargs(t_pipe *pipe_info, t_list *arg_lst)
{
	t_list	*cmd_args;

	cmd_args = 0;
	while (arg_lst)
	{
		if (get_redir_type(arg_lst->content))
			arg_lst = arg_lst->next;
		else
		{
			if (add_cmd_arg(&cmd_args, arg_lst->content))
				return (1);
		}
		arg_lst = arg_lst->next;
	}
	pipe_info->cmdargs = cmd_args_ll2list(cmd_args);
	if (!pipe_info->cmdargs)
		return (1);
	pipe_info->cmd = pipe_info->cmdargs[0];
	ft_lstclear(&cmd_args, del_function_void);
	return (0);
}

static char	**cmd_args_ll2list(t_list *cmd_args)
{
	char	**list;
	int		i;

	list = ft_calloc(ft_lstsize(cmd_args) + 1, sizeof(char *));
	if (!list)
		return (0);
	i = -1;
	while (cmd_args)
	{
		list[++i] = (char *)cmd_args->content;
		cmd_args = cmd_args->next;
	}
	return (list);
}

static int	add_cmd_arg(t_list **cmd_args, char *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		return (1);
	if (*cmd_args)
		ft_lstadd_back(cmd_args, new);
	else
		*cmd_args = new;
	return (0);
}

static void	del_function_void(void *content)
{
	(void)content;
}
