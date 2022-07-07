/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:31:42 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/06/27 16:53:06 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	error_redir(char *str, t_list *env);
static int	next_redir(char c, char next);
int			check_pipe_error(char *str, t_list *env);

int	check_error(char *str, t_list *env)
{
	if (!quote_error_nb(str))
	{
		ft_putstr_fd("minishell: quote error\n", 2);
		return (0);
	}
	if (!error_redir(str, env) || !check_pipe_error(str, env))
		return (0);
	return (1);
}

static int	error_redir(char *str, t_list *env)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>' || str[i] == '<')
		{
			if (((str[i + 1] == '<' || str[i + 1] == '>')
					&& (str[i + 2] == '<' || str[i + 2] == '>'))
				|| !next_redir(str[i], str[i + 1]))
			{
				ft_putstr_fd("minishell: redirection error\n", 2);
				set_exit_status(&env, 2);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

static int	next_redir(char c, char next)
{
	if ((c == '<' && next == '>')
		|| (c == '>' && next == '<'))
		return (0);
	return (1);
}

int	skip_quote(char *str, char c, int index)
{
	if (str[index] == c)
	{
		index++;
		while (str[index] != c && str[index] != 0)
			index++;
		if (str[index] == 0)
			return (-1);
	}
	return (index);
}

int	check_pipe_error(char *str, t_list *env)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '|' && str[i + 1] == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `||'\n", 2);
		set_exit_status(&env, 2);
		return (0);
	}
	else if (str[i] == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		set_exit_status(&env, 2);
		return (0);
	}
	return (1);
}

// static int	error_quote(char *str)
// {
// 	int	nb;
// 	int	i;

// 	i = 0;
// 	nb = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '"')
// 			nb++;
// 		i++;
// 	}
// 	if (nb % 2 == 0)
// 		return (1);
// 	else
// 	{
// 		printf("Quote error\n");
// 		return (0);
// 	}
// }
