/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:32:08 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/11 14:32:29 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "env_lst.h"

static void	print_sorted(t_list *env);
static char	**export_env_list_create(t_list *env);

int	builtin_export(t_pipe pipe, t_list **env, int forked)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (pipe.cmdargs[++i])
	{
		if (!forked && env_export(env, pipe.cmdargs[i]))
		{
			res = 1;
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(pipe.cmdargs[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
		}
	}
	if (i == 1 && forked)
		print_sorted(*env);
	return (res);
}

static char	**export_env_list_create(t_list *env)
{
	char	**envp;
	int		i;

	envp = ft_calloc(ft_lstsize(env) + 1, sizeof(char *));
	if (!envp)
		return (0);
	i = -1;
	while (env)
	{
		if (((char **)env->content)[0][0] != '?')
		{
			if (((char **)env->content)[1])
				envp[++i] = ft_strjoin3(((char **)env->content)[0], "=",
						((char **)env->content)[1]);
			else
				envp[++i] = ft_strdup(((char **)env->content)[0]);
			if (!envp[i])
				return (0);
		}
		env = env->next;
	}
	return (envp);
}

static size_t	get_big(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	bubblesort_envp(char **envp)
{
	int		i;
	int		changes;
	char	*tmp;

	changes = 1;
	while (changes)
	{
		i = 0;
		changes = 0;
		while (envp[++i])
		{
			if (ft_strncmp(envp[i - 1], envp[i],
					get_big(ft_strlen(envp[i - 1]), ft_strlen(envp[i]))) > 0)
			{
				changes++;
				tmp = envp[i];
				envp[i] = envp[i - 1];
				envp[i - 1] = tmp;
			}
		}
	}
}

static void	print_sorted(t_list *env)
{
	char	**envp;
	int		i;

	(void)env;
	envp = export_env_list_create(env);
	if (!envp)
		return ;
	bubblesort_envp(envp);
	i = -1;
	while (envp[++i])
	{
		printf("declare -x %s\n", envp[i]);
		free(envp[i]);
	}
	free(envp);
}
