/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:25:09 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/15 19:04:37 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

#define DIRNAME_BUFFER_SIZE 4096

int	builtin_pwd(void)
{
	char	*current_path;

	current_path = get_current_dir();
	if (!current_path)
		return (1);
	printf("%s\n", current_path);
	free(current_path);
	return (0);
}

char	*get_current_dir(void)
{
	char	*dirname;

	dirname = ft_calloc(DIRNAME_BUFFER_SIZE, sizeof(char));
	if (!dirname)
		return (0);
	if (!getcwd(dirname, DIRNAME_BUFFER_SIZE))
	{
		perror("minishell: getcwd");
		return (0);
	}
	return (dirname);
}
