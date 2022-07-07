/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:24:25 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/23 14:16:34 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "env_lst.h"

int	g_manage_sigint = -1;

int	open_ears_signals(void)
{
	if (listen_signal(SIGQUIT))
	{
		perror("minishell: sigaction");
		return (1);
	}
	if (listen_signal(SIGINT))
	{
		perror("minishell: sigaction");
		return (1);
	}
	return (0);
}

// in bash SIGINT prints "^C", unable to do the same here
void	action_sigint(void)
{
	rl_on_new_line();
	if (g_manage_sigint >= 0)
	{
		rl_replace_line("", 0);
		ft_putstr_fd("\n", 1);
		rl_redisplay();
	}
	g_manage_sigint = 1;
}

// in bash SIGQUIT sometimes doesn't print anything (top)
// sometimes it prints "^\" (sleep 9 | echo 5)
// other times it prints "^\ (Quit) Core Dumped" (sleep 9)
void	action_sigquit(void)
{
	if (g_manage_sigint < 0)
	{
		g_manage_sigint = 2;
	}
	else
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	manage_sigint(t_list **env)
{
	if (g_manage_sigint == 1)
		set_exit_status(env, 130);
	if (g_manage_sigint == 2)
		set_exit_status(env, 131);
	g_manage_sigint = -1;
}
