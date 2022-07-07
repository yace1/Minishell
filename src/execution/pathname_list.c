/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:58:46 by davifah           #+#    #+#             */
/*   Updated: 2022/05/31 11:39:48 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	**create_pathname_list(char *cmd, char *paths);

char	**get_pathname_list(char *cmd, t_list *env)
{
	char	**paths;

	while (env && ft_strncmp(((char **)env->content)[0], "PATH", 5))
		env = env->next;
	if (!env)
		paths = create_pathname_list(cmd, "");
	else
		paths = create_pathname_list(cmd, ((char **)env->content)[1]);
	return (paths);
}

static int	get_paths_size(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		continue ;
	return (i);
}

static void	free_paths(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

static char	**create_pathname_list(char *cmd, char *paths)
{
	char	**split;
	char	**pathnames;
	int		i;

	split = ft_split(paths, ':');
	if (!split)
		return (0);
	pathnames = ft_calloc(get_paths_size(split) + 2, sizeof(char *));
	if (!pathnames)
		return (0);
	pathnames[0] = cmd;
	i = -1;
	while (split[++i])
	{
		pathnames[i + 1] = ft_strjoin3(split[i], "/", cmd);
		if (!pathnames[i + 1])
			return (0);
	}
	free_paths(split);
	return (pathnames);
}

void	free_pathname_list(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
	{
		if (i)
			free(paths[i]);
	}
	free(paths);
}
