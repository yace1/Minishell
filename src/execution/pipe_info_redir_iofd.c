/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_info_redir_iofd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:48:41 by dfarhi            #+#    #+#             */
/*   Updated: 2022/05/27 13:34:01 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	get_redir_fd(t_pipe *pipe_info, t_redir redir, char *arg);
static int	open_outfile(int *fdout, t_redir redir, char *arg);
static int	open_infile(int *fdin, char *arg);

int	get_in_out_fd(t_pipe *pipe_info, t_list *arg_lst)
{
	t_redir	redir;

	pipe_info->io_error = 0;
	pipe_info->fdin = -1;
	pipe_info->fdout = -1;
	while (arg_lst && !pipe_info->io_error)
	{
		redir = get_redir_type(arg_lst->content);
		arg_lst = arg_lst->next;
		if ((redir == input || redir == i_heredoc) && pipe_info->fdin > 1)
			close(pipe_info->fdin);
		if ((redir == output || redir == o_append) && pipe_info->fdout > 1)
			close(pipe_info->fdout);
		if (redir && get_redir_fd(pipe_info, redir, arg_lst->content))
			return (1);
	}
	return (0);
}

static int	get_redir_fd(t_pipe *pipe_info, t_redir redir, char *arg)
{
	int	res;

	if (redir == input)
		res = open_infile(&pipe_info->fdin, arg);
	if (redir == i_heredoc)
		res = minishell_heredoc(&pipe_info->fdin, arg);
	if (redir == output || redir == o_append)
		res = open_outfile(&pipe_info->fdout, redir, arg);
	if (res < 0)
		pipe_info->io_error = 1;
	return (res > 0);
}

static int	open_infile(int *fdin, char *arg)
{
	char	*error_str;

	*fdin = open(arg, O_RDONLY);
	if (*fdin < 0)
	{
		error_str = ft_strjoin("minishell: ", arg);
		if (!error_str)
			return (1);
		perror(error_str);
		free(error_str);
		return (-1);
	}
	return (0);
}

static int	open_outfile(int *fdout, t_redir redir, char *arg)
{
	int		flags;
	char	*error_str;

	flags = O_WRONLY | O_CREAT;
	if (redir == o_append)
		flags = flags | O_APPEND;
	else
		flags = flags | O_TRUNC;
	*fdout = open(arg, flags, 0644);
	if (*fdout < 0)
	{
		error_str = ft_strjoin("minishell: ", arg);
		if (!error_str)
			return (1);
		perror(error_str);
		free(error_str);
		return (-1);
	}
	return (0);
}
