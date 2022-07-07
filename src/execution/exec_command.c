/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:29:18 by davifah           #+#    #+#             */
/*   Updated: 2022/06/21 09:41:03 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "env_lst.h"

static void	command_not_found_clear_print(t_pipe pipe,
				char **pathname, char **envp);

int	fork_command(t_pipe pipe, t_list **env)
{
	int	fork_res;

	if (!ft_strncmp(pipe.cmd, "exit", 5))
		pipe.exit_exit_status = builtin_exit(pipe);
	if (!ft_strncmp(pipe.cmd, "export", 7))
		pipe.exit_exit_status = builtin_export(pipe, env, 0);
	if (!ft_strncmp(pipe.cmd, "unset", 6))
		pipe.exit_exit_status = builtin_unset(pipe, env);
	if (!ft_strncmp(pipe.cmd, "cd", 3))
		pipe.exit_exit_status = builtin_cd(pipe, env);
	fork_res = fork();
	if (fork_res < 0)
		perror("minishell: fork: ");
	else if (!fork_res)
	{
		if (is_builtin(pipe.cmd))
			exec_builtin(pipe, env);
		else
			exec_command(pipe, *env);
	}
	return (fork_res);
}

void	exec_command(t_pipe pipe, t_list *env)
{
	int		i;
	char	**pathname;
	char	**envp;

	if (pipe.io_error)
		exit(1);
	if (!pipe.cmd)
		exit(0);
	envp = envlst_to_envp(env);
	pathname = get_pathname_list(pipe.cmd, env);
	if (!pathname || !envp || dup_fd_io(pipe))
		exit(127);
	i = -1;
	while (pathname[++i])
	{
		execve(pathname[i], pipe.cmdargs, envp);
	}
	command_not_found_clear_print(pipe, pathname, envp);
	exit(127);
}

int	dup_fd_io(t_pipe pipe)
{
	int	fdout;

	fdout = pipe.pipe_output;
	if (pipe.fdout >= 0)
		fdout = pipe.fdout;
	if (fdout >= 0)
	{
		if (dup2(fdout, 1) == -1)
			return (1);
	}
	if (pipe.fdin > 1 && dup2(pipe.fdin, 0) == -1)
		return (1);
	if (pipe.fdin > 1)
		close(pipe.fdin);
	if (pipe.fdout > 1)
		close(pipe.fdout);
	if (pipe.pipe_output > 1)
		close(pipe.pipe_output);
	if (pipe.pipe_input > 1)
		close(pipe.pipe_input);
	return (0);
}

static void	command_not_found_clear_print(t_pipe pipe,
				char **pathname, char **envp)
{
	int	i;

	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(pipe.cmd, 2);
	ft_putstr_fd(": command not found...\n", 2);
	free_pathname_list(pathname);
	i = -1;
	while (envp[++i])
		free(envp[i]);
	free(envp);
}
