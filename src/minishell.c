/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:14:00 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/27 18:09:46 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_lst.h"
#include "execution.h"
#include "signals.h"
#include "debug.h"

static int	prompt_loop_main(char *prompt, t_list **env);
static void	debug_envvar_n(t_list *env, char **envp);

int	main(int ac, char **av, char **envp)
{
	char	*prompt;
	t_list	*env;
	int		exit_status;

	(void)ac;
	(void)av;
	prompt = make_prompt(envp);
	env = create_env_list(envp);
	debug_envvar_n(env, envp);
	if (!prompt || !env || open_ears_signals() || configure_termius(start))
		exit (1);
	display_banner();
	exit_status = prompt_loop_main(prompt, &env);
	ft_lstclear(&env, free_env_lst_content);
	free(prompt);
	configure_termius(end);
	return (exit_status);
}

static void	debug_envvar_n(t_list *env, char **envp)
{
	int	i;

	if (!DEBUG_ENVVAR_N)
		return ;
	i = -1;
	while (envp[++i])
		continue ;
	if (i != ft_lstsize(env) - 1)
		printf("ERROR WITH NUMBER OF ENV VARIABLES, envlst %d - envp %d\n",
			ft_lstsize(env) - 1, i);
}

static int	prompt_loop_main(char *prompt, t_list **env)
{
	char	*prompt_buff;
	t_list	*line;
	int		exec_res;
	int		exit_code;

	while (1)
	{
		manage_sigint(env);
		g_manage_sigint = 0;
		prompt_buff = readline(prompt);
		manage_sigint(env);
		if (!prompt_buff)
		{
			ft_putstr_fd("exit\n", 2);
			return (0);
		}
		if (ft_strlen(prompt_buff))
			add_history(prompt_buff);
		line = parsing(prompt_buff, *env);
		exec_res = execute(line, env, &exit_code);
		free_lst(line);
		free(prompt_buff);
		if (exec_res)
			return (exit_code);
	}
}
