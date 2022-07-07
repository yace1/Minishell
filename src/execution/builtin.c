/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:35:13 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/15 19:23:50 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	is_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 5) || !ft_strncmp(cmd, "cd", 3)
		|| !ft_strncmp(cmd, "pwd", 4) || !ft_strncmp(cmd, "export", 7)
		|| !ft_strncmp(cmd, "unset", 6) || !ft_strncmp(cmd, "env", 4)
		|| !ft_strncmp(cmd, "exit", 5))
		return (1);
	return (0);
}

void	exec_builtin(t_pipe pipe, t_list **env)
{
	dup_fd_io(pipe);
	if (!ft_strncmp(pipe.cmd, "echo", 5))
		exit(builtin_echo(pipe));
	if (!ft_strncmp(pipe.cmd, "cd", 3))
		exit(pipe.exit_exit_status);
	if (!ft_strncmp(pipe.cmd, "pwd", 4))
		exit(builtin_pwd());
	if (!ft_strncmp(pipe.cmd, "export", 7))
	{
		builtin_export(pipe, env, 1);
		exit(pipe.exit_exit_status);
	}
	if (!ft_strncmp(pipe.cmd, "unset", 6))
		exit(pipe.exit_exit_status);
	if (!ft_strncmp(pipe.cmd, "env", 4))
		exit(builtin_env(*env));
	if (!ft_strncmp(pipe.cmd, "exit", 5))
		exit(pipe.exit_exit_status);
	exit(127);
}
