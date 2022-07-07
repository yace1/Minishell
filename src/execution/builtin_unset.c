/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:02:00 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/15 14:49:53 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "env_lst.h"

static int	get_env_pos_inlist(char *envname, t_list *env);

int	builtin_unset(t_pipe pipe, t_list **env)
{
	int	i;
	int	pos;

	i = 0;
	while (pipe.cmdargs[++i])
	{
		pos = get_env_pos_inlist(pipe.cmdargs[i], *env);
		if (pos >= 0)
			ft_lstdelone(ft_lstremove_index(env, pos), free_env_lst_content);
	}
	return (0);
}

static int	get_env_pos_inlist(char *envname, t_list *env)
{
	int	i;

	i = 0;
	while (env)
	{
		if (!ft_strncmp(envname,
				((char **)env->content)[0], ft_strlen(envname) + 1))
			return (i);
		env = env->next;
		i++;
	}
	return (-1);
}
