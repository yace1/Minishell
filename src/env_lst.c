/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:55:00 by dfarhi            #+#    #+#             */
/*   Updated: 2022/05/24 21:00:22 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_lst.h"

/*
 *	env does not print items with content[1] == NULL but export does
*/

t_list	*create_env_list(char **envp)
{
	t_list	*env_lst;
	int		i;

	i = -1;
	env_lst = 0;
	while (envp[++i])
	{
		if (env_export(&env_lst, envp[i]) == 1)
			return (0);
	}
	if (set_exit_status(&env_lst, 0))
		return (0);
	return (env_lst);
}

int	set_exit_status(t_list **env, int status)
{
	char	*str;
	char	*status_str;

	status_str = ft_itoa(status);
	if (!status_str)
		return (1);
	str = ft_strjoin("?=", status_str);
	if (!str)
		return (1);
	if (env_export(env, str))
		return (1);
	free(status_str);
	free(str);
	return (0);
}

//ft_lstiter(env_lst, print_env_list);
void	print_env_list(void *content)
{
	char	**env_var;

	env_var = (char **)content;
	if (env_var[1])
		printf("%s=%s\n", env_var[0], env_var[1]);
	else
		printf("%s\n", env_var[0]);
}

//ft_lstclear(&env_lst, free_env_lst_content);
//ft_lstdelone(item, free_env_lst_content);
void	free_env_lst_content(void *content)
{
	free(((char **)content)[0]);
	if (((char **)content)[1])
		free(((char **)content)[1]);
	free(content);
}
