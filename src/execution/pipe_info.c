/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:21:01 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/09 14:47:54 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "env_lst.h"
#include "minishell.h"
#include "debug.h"

int	get_pipe_info(t_pipe *pipe_info, t_list *line, t_list *next, t_list **env)
{
	if (get_cmdargs(pipe_info, ((t_data *)line->content)->arg_lst))
		return (1);
	if (get_in_out_fd(pipe_info, ((t_data *)line->content)->arg_lst))
		return (1);
	if ((pipe_info->fdin > 1 || pipe_info->fdout > 1 || pipe_info->io_error)
		&& set_exit_status(env, pipe_info->io_error))
		return (1);
	if (get_pipe_io(pipe_info, next))
		return (1);
	if (DEBUG_PRINT_PIPE_INFO)
		print_pipe_info(*pipe_info);
	return (0);
}

void	print_pipe_info(t_pipe pipe)
{
	int	i;

	if (pipe.io_error)
		printf("io_error!\n");
	printf("fdin: %d - fdout %d\n", pipe.fdin, pipe.fdout);
	printf("pipe: input %d output %d\n", pipe.pipe_input, pipe.pipe_output);
	printf("command: %s\n", pipe.cmd);
	i = -1;
	printf("cmd + args:");
	while (pipe.cmdargs[++i])
		printf(" %s", pipe.cmdargs[i]);
	printf("\n\n");
}

void	free_close_pipe_info(t_pipe pipe)
{
	free(pipe.cmdargs);
	if (pipe.fdin > 1)
		close(pipe.fdin);
	if (pipe.fdout > 1)
		close(pipe.fdout);
	if (pipe.pipe_output > 1)
		close(pipe.pipe_output);
}
