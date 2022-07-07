/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:01:13 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/06/27 17:33:57 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "debug.h"

/* -------------------  PARSING CHECKLIST  ----------------------
- double quote 						DONE (no simple quote or var in it)
- separate by space simple case		DONE
- handling pipe 					DONE
- no imput 							DONE
- normal redirection 				DONE
- double redirection 				DONE
- Free								DONE (il faut check plus de test)
- Malloc protection					DONE
- Norminette						DONE (plus au moins)
- env variable 						PENDING a revoir (error whith consecutive)
- simple quote 						PENDING
- multiple simple quote 			PENDING

Error: 
	- prompt pour insertion en cas de pipe sans commande apres "echo cmd | "
	- minishell: syntax error near unexpected token  '>' ou '<'
*/

static char	*fill_arg(t_list *lst, char *str, t_list *env);
int			print_quote_error(char *error, t_list *lst);
int			check_after_quote(t_list *temp_second, t_list *lst);
static int	add_pipe(char *str, t_list *temp, t_list *lst, t_list *env);

t_list	*parsing(char *str, t_list *env)
{
	t_list	*lst;
	t_list	*temp;

	str = skip_space(str, 0);
	if (!check_error(str, env) || !*str || *str == '|')
		return (0);
	lst = ft_lstnew((t_data *)ft_calloc(1, sizeof(t_data)));
	if (!lst)
		return (0);
	temp = lst;
	if (!add_pipe(str, temp, lst, env))
		return (0);
	if (!redir_is_alone(lst, env))
		return (0);
	if (DEBUG_PRINT_PIPE_ARGS)
		print_linked_lst(lst);
	return (lst);
}

static int	add_pipe(char *str, t_list *temp, t_list *lst, t_list *env)
{
	while (*str)
	{
		((t_data *)temp->content)->arg_lst = ft_lstnew(NULL);
		str = fill_arg(temp, str, env);
		if (!str)
			return (0);
		if (*str)
		{
			temp = ft_calloc(1, sizeof(t_list));
			temp->content = ft_calloc(1, sizeof(t_data));
			if (!temp || !temp->content)
				return (0);
			ft_lstadd_back(&lst, temp);
		}
	}
	return (1);
}

static char	*fill_arg(t_list *lst, char *str, t_list *env)
{
	t_list	*tmp;

	tmp = ((t_data *)lst->content)->arg_lst;
	while (*str != '|' && *str != 0 && str != 0)
	{
		str = skip_space(str, 0);
		str = fill_quote(tmp, str, &(((t_data *)lst->content)->arg_lst), env);
		str = fill_s_quote(tmp, str, &(((t_data *)lst->content)->arg_lst), env);
		str = check_redir(tmp, str, &(((t_data *)lst->content)->arg_lst));
		str = nrml_arg(tmp, str, &(((t_data *)lst->content)->arg_lst), env);
		str = check_env_var(str, tmp, env);
		if (!str)
			return (0);
		tmp = ft_lstlast(tmp);
	}
	((t_data *)lst->content)->arg_lst
		= clear_lst(((t_data *)lst->content)->arg_lst);
	if (*str == '|')
		str++;
	return (str);
}

int	arg_size(char *str)
{
	int	i;

	i = 0;
	while (!ft_isspace(str[i]) && str[i] != '|' && str[i] != 0 && str[i] != 39
		&& str[i] != '"' && str[i] != '>' && str[i] != '<' && str[i] != '$')
		i++;
	return (i);
}

int	ft_isalnum_under(int c, int index)
{
	int	flag;

	flag = 1;
	if (c == '?' && index != 0)
		flag = 0;
	if (ft_isdigit(c) || ft_isalpha(c) || c == '_' || c == '?')
		return (1 * flag);
	return (0);
}
