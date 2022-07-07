/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:03:59 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/17 09:57:45 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

int	listen_signal(int sig)
{
	int					r;
	struct sigaction	s;

	s.sa_sigaction = &action_on_signal;
	sigemptyset(&s.sa_mask);
	s.sa_flags = 0;
	r = sigaction(sig, &s, NULL);
	return (r);
}

void	action_on_signal(int sig, siginfo_t *info, void *unused)
{
	(void)info;
	(void)unused;
	if (sig == SIGQUIT)
		action_sigquit();
	if (sig == SIGINT)
		action_sigint();
}

int	configure_termius(t_program_side pos)
{
	static struct termios	term;

	if (pos == start)
	{
		if (tcgetattr(0, &term))
		{
			perror("minishell: tcgetsttr");
			return (1);
		}
		if (term_disable_ctrl_print(term))
			return (1);
	}
	else if (pos == end)
	{
		if (tcsetattr(0, 0, &term))
		{
			perror("minishell: tcsetattr");
			return (1);
		}
	}
	return (0);
}

int	term_disable_ctrl_print(struct termios term)
{
	term.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &term))
	{
		perror("minishell: tcsetattr");
		return (1);
	}
	return (0);
}
