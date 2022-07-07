/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:01:18 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/06/27 17:58:19 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define BANNER_PATH "assets/banner.txt"

char	*build_prompt(char *user);

void	display_banner(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	fd = open(BANNER_PATH, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(BANNER_PATH);
		return ((void)(0));
	}
	line = get_next_line(fd);
	while (line && i++)
	{
		if (i % 2 == 0)
			printf(BLU "%s" RESET, line);
		else
			printf(MAG "%s" RESET, line);
		free(line);
		line = get_next_line(fd);
	}
	printf("\n");
}

char	*make_prompt(char **env)
{
	char	*prompt;
	char	*user;
	char	*colored;
	char	*completed;
	int		i;

	i = 0;
	user = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "USER=", 5))
		{
			user = ft_strnstr(env[i], "USER", 4) + 5;
			break ;
		}
		i++;
	}
	completed = build_prompt(user);
	colored = ft_strjoin(BLU, completed);
	prompt = ft_strjoin(colored, RESET);
	free(completed);
	free(colored);
	return (prompt);
}

char	*build_prompt(char *user)
{
	char	*completed;

	if (user == NULL)
	{
		user = ft_strdup("");
		completed = ft_strjoin(user, "@Minishell>");
		free(user);
	}
	else
		completed = ft_strjoin(user, "@Minishell>");
	return (completed);
}

char	*skip_space(char *str, int size)
{
	str += size;
	while (ft_isspace(*str))
		str++;
	return (str);
}

char	*strjoin_free(char *s1, char *s2, int is_malloc)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s1, len1);
	ft_memcpy(&ptr[len1], s2, len2);
	if (s1)
		free(s1);
	if (is_malloc)
		free(s2);
	ptr[len1 + len2] = 0;
	return (ptr);
}
