/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:24:39 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/11 15:18:52 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "env_lst.h"

/*
 *	UNSOLVED CASES / TODO
 *	- CAT | CAT | LS
*/

static int	pid_list_add(t_list **pid_lst, int pid);
static int	wait_pids(t_list **pid_lst, t_list **env);

int	execute(t_list *line, t_list **env, int *exit_code)
{
	t_pipe	pipe_info;
	t_list	*pids;
	int		is_exit;

	pids = 0;
	pipe_info.pipe_input = -1;
	pipe_info.exit_code = exit_code;
	*exit_code = 1;
	pipe_info.is_exit = &is_exit;
	*pipe_info.is_exit = 0;
	pipe_info.pipe_n = ft_lstsize(line);
	while (line)
	{
		if (get_pipe_info(&pipe_info, line, line->next, env))
			return (1);
		if (pipe_info.cmd && pid_list_add(&pids, fork_command(pipe_info, env)))
			return (1);
		line = line->next;
		free_close_pipe_info(pipe_info);
	}
	if (wait_pids(&pids, env))
		return (1);
	if (*pipe_info.is_exit)
		return (1);
	return (0);
}

static int	wait_pids(t_list **pid_lst, t_list **env)
{
	int	exit_status;

	while (*pid_lst)
	{
		waitpid(*(int *)(*pid_lst)->content, &exit_status, 0);
		if (WIFEXITED(exit_status)
			&& set_exit_status(env, WEXITSTATUS(exit_status)))
			return (1);
		ft_lstdelone(ft_lstremove_index(pid_lst, 0), free);
	}
	return (0);
}

static int	pid_list_add(t_list **pid_lst, int pid)
{
	int		*content;
	t_list	*new;

	if (pid <= 0)
		return (0);
	content = ft_calloc(1, sizeof(int));
	if (!content)
		return (1);
	*content = pid;
	new = ft_lstnew(content);
	if (!new)
		return (1);
	if (!*pid_lst)
		*pid_lst = new;
	else
		ft_lstadd_back(pid_lst, new);
	return (0);
}

t_redir	get_redir_type(void *content)
{
	if (!ft_strncmp((char *)content, "<", 2))
		return (input);
	if (!ft_strncmp((char *)content, "<<", 3))
		return (i_heredoc);
	if (!ft_strncmp((char *)content, ">", 2))
		return (output);
	if (!ft_strncmp((char *)content, ">>", 3))
		return (o_append);
	return (none);
}
