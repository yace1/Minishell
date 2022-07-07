/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nrml_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:50:40 by ybentaye          #+#    #+#             */
/*   Updated: 2022/06/27 18:10:24 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//ERROR with "$USER" $PWD but not with "$USER " $PWD

static char	*env_in_lst(char *var_key, char *str, t_list *arg, t_list *tmp_env);
static char	*add_special(char *str, t_list *arg);

char	*nrml_arg(t_list *tmp, char *str, t_list **lst, t_list *env)
{
	char	*to_add;

	(void)env;
	tmp = ft_lstlast(tmp);
	if (*str != '|' && *str != 0 && *str != '"'
		&& *str != '$' && *str != 39)
	{
		str = skip_space(str, 0);
		tmp = ft_lstlast(tmp);
		to_add = ft_calloc(arg_size(str) + 1, sizeof(char));
		ft_strlcat(to_add, str, arg_size(str) + 1);
		add_content_last(tmp, to_add, 1);
		if (check_nxt_char(str))
			add_back_new_lst(lst);
		str = skip_space(str, 0);
		str += arg_size(str);
		str = skip_space(str, 0);
	}
	return (str);
}

char	*check_redir(t_list *tmp, char *str, t_list **lst)
{
	char	*redir;
	int		i;

	i = 1;
	if (*str == '>' || *str == '<')
	{
		redir = ft_calloc(3, sizeof(char));
		if (!redir)
			return (0);
		tmp = ft_lstlast(tmp);
		redir[0] = *str;
		if (str[1] == '>' || str[1] == '<')
		{
			redir[1] = str[1];
			i++;
		}
		add_content_last(tmp, redir, 1);
		add_back_new_lst(lst);
		str += i;
		return (str);
	}
	return (str);
}

char	*check_env_var(char *str, t_list *arg, t_list *env)
{
	int		i;
	char	*var_key;
	t_list	*tmp_env;

	i = 0;
	tmp_env = env;
	if (*str == '$')
	{
		str++;
		while (ft_isalnum_under(str[i], i))
			i++;
		var_key = ft_calloc(i + 3, sizeof(char));
		ft_strlcpy(var_key, str, i + 1);
		tmp_env = env;
		while (tmp_env)
		{
			if (ft_strnstr((((char **)tmp_env->content)[0]), var_key, i + 1)
			&& ((char **)tmp_env->content)[0][i] == 0)
				return (env_in_lst(var_key, str, arg, tmp_env));
			tmp_env = tmp_env->next;
		}
		free (var_key);
		return (skip_space(str, i));
	}
	return (str);
}

static char	*env_in_lst(char *var_key, char *str, t_list *arg, t_list *tmp_env)
{
	char	*var_val;
	int		i;

	arg = ft_lstlast(arg);
	i = ft_strlen(var_key);
	if (((char **)tmp_env->content)[1])
	{
		var_val = ft_strdup(((char **)tmp_env->content)[1]);
		add_content_last(arg, var_val, 1);
		str += i;
		str = add_special(str, arg);
		if (*str != '"' && *str != '$' && *str != 39)
			add_back_new_lst(&arg);
		free (var_key);
		return (skip_space(str, 0));
	}
	free (var_key);
	str += i;
	return (skip_space(str, 0));
}

static char	*add_special(char *str, t_list *arg)
{
	char	*tmp;
	int		i;

	i = 0;
	if (*str == ':' || *str == '/' || *str == 92 || *str == '.')
	{
		while (str[i] == ':' || str[i] == '/' || str[i] == 92 || str[i] == '.')
			i++;
		tmp = ft_calloc(i + 1, sizeof(char));
		i = 0;
		while (*str == ':' || *str == '/' || *str == 92 || *str == '.')
		{
			tmp[i] = *str;
			i++;
			str++;
		}
		tmp[i] = 0;
		add_content_last(arg, tmp, 1);
		return (str);
	}
	return (str);
}
