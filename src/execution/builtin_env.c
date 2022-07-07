/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:29:09 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/10 11:33:57 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	builtin_env(t_list *env)
{
	while (env)
	{
		if (ft_strncmp(((char **)env->content)[0], "?", 2)
				&& ((char **)env->content)[1])
		{
			printf("%s=%s\n", ((char **)env->content)[0],
				((char **)env->content)[1]);
		}
		env = env->next;
	}
	return (0);
}
