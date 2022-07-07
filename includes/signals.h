/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:12:44 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/17 09:52:53 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "expanded.h"

// SIGNALS
// Ctrl + C : SIGINT
// Ctrl + \ : SIGQUIT

typedef enum e_program_side
{
	start,
	end,
}	t_program_side;

extern int	g_manage_sigint;

int		listen_signal(int sig);
int		open_ears_signals(void);
void	action_on_signal(int sig, siginfo_t *info, void *unused);
void	action_sigint(void);
void	action_sigquit(void);
void	manage_sigint(t_list **env);
int		configure_termius(t_program_side pos);
int		term_disable_ctrl_print(struct termios term);

#endif
