/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:05:00 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/21 10:46:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "env_lst.h"
#include "parsing.h"

static int	is_valid_exit_args(char **cmdargs);
static int	set_exit_code(t_pipe pipe);
static int	word_is_digit(char *word);

int	builtin_exit(t_pipe pipe)
{
	int	res;

	res = 0;
	ft_putstr_fd("exit\n", 2);
	if (!is_valid_exit_args(pipe.cmdargs))
		res = 1;
	if (!res)
		res = set_exit_code(pipe);
	return (res);
}

static int	set_exit_code(t_pipe pipe)
{
	if (pipe.pipe_n == 1)
		*(pipe.is_exit) = 1;
	*(pipe.exit_code) = 0;
	if (pipe.cmdargs[1])
	{
		if (word_is_digit(pipe.cmdargs[1]))
			*(pipe.exit_code) = ft_atoi(pipe.cmdargs[1]);
		else
		{
			*(pipe.exit_code) = 2;
			return (2);
		}
	}
	return (0);
}

static int	is_valid_exit_args(char **cmdargs)
{
	if (cmdargs[1] && !word_is_digit(cmdargs[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmdargs[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (1);
	}
	if (word_list_size(cmdargs) > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (0);
	}
	return (1);
}

int	word_list_size(char **list)
{
	int	i;

	i = -1;
	while (list[++i])
		continue ;
	return (i);
}

static int	word_is_digit(char *word)
{
	int	i;

	i = -1;
	while (word[++i])
	{
		if (!i && word[i] == '-')
			continue ;
		if (!ft_isdigit(word[i]))
			return (0);
	}
	return (1);
}
