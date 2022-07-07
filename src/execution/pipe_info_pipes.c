/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_info_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:21:44 by davifah           #+#    #+#             */
/*   Updated: 2022/06/19 11:12:09 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	get_pipe_io(t_pipe *pipe_info, t_list *next)
{
	int	fd[2];

	pipe_info->pipe_output = -1;
	if (pipe_info->fdin < 0 && pipe_info->pipe_input > 1)
		pipe_info->fdin = pipe_info->pipe_input;
	else if (pipe_info->pipe_input > 1)
	{
		close(pipe_info->pipe_input);
		pipe_info->pipe_input = -1;
	}
	if (next)
	{
		if (pipe((int *)fd))
		{
			perror("minishell: pipe: ");
			return (1);
		}
		pipe_info->pipe_output = fd[1];
		pipe_info->pipe_input = fd[0];
	}
	if (pipe_info->fdin < 0)
		pipe_info->fdin = 1;
	if (pipe_info->pipe_output < 0)
		pipe_info->pipe_output = 1;
	return (0);
}
