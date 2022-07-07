/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:25:04 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/15 19:36:56 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "expanded.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipe
{
	char	*cmd;
	char	**cmdargs;
	int		fdin;
	int		fdout;
	int		pipe_input;
	int		pipe_output;
	int		io_error;
	int		*exit_code;
	int		*is_exit;
	int		exit_exit_status;
	int		pipe_n;
}	t_pipe;

typedef enum e_redir
{
	none,
	input,
	i_heredoc,
	output,
	o_append,
}	t_redir;

int		execute(t_list *line, t_list **env, int *exit_code);
void	print_pipe_info(t_pipe pipe);
void	free_close_pipe_info(t_pipe pipe);
t_redir	get_redir_type(void *content);
int		get_pipe_info(t_pipe *pipe_info, t_list *line,
			t_list *next, t_list **env);
int		get_cmdargs(t_pipe *pipe_info, t_list *arg_lst);
int		get_in_out_fd(t_pipe *pipe_info, t_list *arg_lst);
int		get_pipe_io(t_pipe *pipe_info, t_list *next);
int		heredoc(char *delimiter, int fdout);
int		minishell_heredoc(int *pipe_fdin, char *delimiter);
char	**get_pathname_list(char *cmd, t_list *env);
void	free_pathname_list(char **paths);
void	exec_command(t_pipe pipe, t_list *env);
int		fork_command(t_pipe pipe, t_list **env);
int		dup_fd_io(t_pipe pipe);

// BUILTINs
int		is_builtin(char *cmd);
void	exec_builtin(t_pipe pipe, t_list **env);
int		word_list_size(char **list);
char	*get_current_dir(void);
int		builtin_exit(t_pipe pipe);
int		builtin_echo(t_pipe pipe);
int		builtin_env(t_list *env);
int		builtin_export(t_pipe pipe, t_list **env, int forked);
int		builtin_unset(t_pipe pipe, t_list **env);
int		builtin_pwd(void);
int		builtin_cd(t_pipe pipe, t_list **env);

#endif
