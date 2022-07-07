/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:17:22 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/15 19:38:12 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "env_lst.h"

static int	manage_errors(char **cmdargs);
static void	update_env_pwd(t_list **env);

int	builtin_cd(t_pipe pipe, t_list **env)
{
	(void)env;
	if (manage_errors(pipe.cmdargs))
		return (1);
	if (chdir(pipe.cmdargs[1]))
	{
		ft_putstr_fd("minishell: cd: ", 2);
		perror(pipe.cmdargs[1]);
		return (1);
	}
	update_env_pwd(env);
	return (0);
}

static int	manage_errors(char **cmdargs)
{
	int	arg_len;

	arg_len = word_list_size(cmdargs);
	if (arg_len != 2)
	{
		if (arg_len > 2)
			ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		else
			ft_putstr_fd("minishell: cd: no argument\n", 2);
		return (1);
	}
	return (0);
}

static void	update_env_pwd(t_list **env)
{
	char	*dirname;
	char	*export_arg;

	dirname = get_current_dir();
	if (!dirname)
		return ;
	export_arg = ft_strjoin("PWD=", dirname);
	free(dirname);
	if (!export_arg)
		return ;
	env_export(env, export_arg);
	free(export_arg);
}
