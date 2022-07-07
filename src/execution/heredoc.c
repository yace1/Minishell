/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:27:24 by dfarhi            #+#    #+#             */
/*   Updated: 2022/05/24 20:15:52 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	str_add_to_list(t_list **lst, char *str);
static void	put_list_fd(t_list *lst, int fd);

int	minishell_heredoc(int *pipe_fdin, char *delimiter)
{
	int	fd[2];

	if (pipe((int *)fd))
	{
		perror("minishell: pipe: ");
		return (1);
	}
	if (heredoc(delimiter, fd[1]))
		return (1);
	close(fd[1]);
	*pipe_fdin = fd[0];
	return (0);
}

int	heredoc(char *delimiter, int fdout)
{
	t_list	*lst;
	char	*str;

	lst = NULL;
	delimiter = ft_strjoin(delimiter, "\n");
	if (!delimiter)
		return (1);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		str = get_next_line(0);
		if (!str)
			return (1);
		if (!ft_strncmp(str, delimiter, ft_strlen(str)))
			break ;
		else if (str_add_to_list(&lst, str))
			return (1);
	}
	free(str);
	put_list_fd(lst, fdout);
	ft_lstclear(&lst, free);
	free(delimiter);
	return (0);
}

static int	str_add_to_list(t_list **lst, char *str)
{
	t_list	*new;

	new = ft_lstnew((void *)str);
	if (!new)
		return (1);
	if (!*lst)
		*lst = new;
	else
		ft_lstadd_back(lst, new);
	return (0);
}

static void	put_list_fd(t_list *lst, int fd)
{
	int		i;
	t_list	*item;

	i = 0;
	while (1)
	{
		item = ft_lstget_index(lst, i);
		if (!item)
			return ;
		ft_putstr_fd(item->content, fd);
		i++;
	}
}
