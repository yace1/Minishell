/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:29:16 by davifah           #+#    #+#             */
/*   Updated: 2022/06/11 14:53:36 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_lst.h"

t_list	*env_is_in_lst(t_list *env_lst, char *arg, int pos)
{
	while (env_lst)
	{
		if ((arg[pos] == '=' || arg[pos] == 0)
			&& (ft_strlen(((char **)env_lst->content)[0])
			== (unsigned long long) pos
			&& !ft_strncmp(arg, ((char **)env_lst->content)[0], pos)))
			return (env_lst);
		env_lst = env_lst->next;
	}
	return (0);
}

int	env_update_value(t_list *env_lst, char *arg, int pos)
{
	char	*value;

	env_lst = env_is_in_lst(env_lst, arg, pos);
	if (!env_lst)
		return (-1);
	if (!((char **)env_lst->content)[1] && !arg[pos])
		return (0);
	if (((char **)env_lst->content)[1] && !arg[pos])
		return (0);
	value = ft_substr(arg, pos + 1, ft_strlen(arg));
	if (!value)
		return (1);
	if (((char **)env_lst->content)[1] && arg[pos] == '=')
		free(((char **)env_lst->content)[1]);
	((char **)env_lst->content)[1] = value;
	return (0);
}
