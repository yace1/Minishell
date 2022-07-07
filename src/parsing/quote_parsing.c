/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:57:03 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/06/27 17:18:22 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*quote_env_var(char *str, t_list *arg, t_list *env);
static char	*env_in_lst(char *var_key, char *str, t_list *arg, t_list *tmp_env);
static char	*quote_filling(char *str, t_list *env, t_list *arg);

char	*fill_quote(t_list *arg, char *str, t_list **lst, t_list *env)
{
	int		i;

	(void)env;
	arg = ft_lstlast(arg);
	if (*str == '"' && *str != '|' && *str != 0)
	{
		i = 0;
		str++;
		while (str[i] != '"')
			i++;
		i = 0;
		str = quote_filling(str, env, arg);
		str++;
		if (ft_isspace(*str))
			add_back_new_lst(lst);
		str = skip_space(str, 0);
	}
	return (str);
}

static char	*quote_filling(char *str, t_list *env, t_list *arg)
{
	char	*c;

	while (*str != '"' && *str != 0)
	{
		c = ft_calloc(2, sizeof(char));
		str = quote_env_var(str, arg, env);
		if (*str != '"' && *str != '$')
		{
			c[0] = *str;
			c[1] = 0;
			add_content_last(arg, c, 1);
			str++;
		}
		else
			free(c);
	}
	return (str);
}

char	*quote_env_var(char *str, t_list *arg, t_list *env)
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
		free (var_key);
		str += i;
		return (str);
	}
	free (var_key);
	str += i;
	return (skip_space(str, 0));
}
