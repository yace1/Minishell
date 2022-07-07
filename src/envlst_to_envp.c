/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_to_envp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:37:59 by davifah           #+#    #+#             */
/*   Updated: 2022/06/11 14:00:32 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_lst.h"

char	**envlst_to_envp(t_list *env)
{
	char	**envp;
	int		i;

	envp = ft_calloc(ft_lstsize(env) + 1, sizeof(char *));
	if (!envp)
		return (0);
	i = -1;
	while (env)
	{
		if (((char **)env->content)[1] && ((char **)env->content)[0][0] != '?')
		{
			envp[++i] = ft_strjoin3(((char **)env->content)[0], "=",
					((char **)env->content)[1]);
			if (!envp[i])
				return (0);
		}
		env = env->next;
	}
	return (envp);
}
