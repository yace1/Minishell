/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifah <dfarhi@student.42lausanne.ch      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:53:09 by davifah           #+#    #+#             */
/*   Updated: 2022/06/09 14:47:18 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_lst.h"
#include "debug.h"

static int	env_update_or_add(t_list **env_lst, char *arg, int pos);
static int	add_env_list(t_list **env_lst, char *arg, int pos);
static int	is_valid_varname_char(char c);

int	env_export(t_list **env_lst, char *arg)
{
	char	*p_pos;
	int		pos;

	p_pos = ft_strchr(arg, '=');
	if (!p_pos)
		pos = ft_strlen(arg);
	else
	{
		pos = p_pos - arg;
	}
	if (check_valid_env_var_name(arg, pos))
	{
		if (DEBUG_PRINT_VARNAME_ERROR)
			printf("%s env var name error\n", arg);
		return (2);
	}
	if (env_update_or_add(env_lst, arg, pos))
		return (1);
	return (0);
}

static int	env_update_or_add(t_list **env_lst, char *arg, int pos)
{
	int	upd_res;

	upd_res = env_update_value(*env_lst, arg, pos);
	if (upd_res > 0 || (upd_res < 0 && add_env_list(env_lst, arg, pos)))
		return (1);
	return (0);
}

static int	add_env_list(t_list **env_lst, char *arg, int pos)
{
	t_list	*new;
	char	**env_var;

	env_var = ft_calloc(2, sizeof(char *));
	if (!env_var)
		return (1);
	env_var[0] = ft_substr(arg, 0, pos);
	if ((unsigned long)pos != ft_strlen(arg))
		env_var[1] = ft_substr(arg, pos + 1, ft_strlen(arg));
	if (!env_var[0] || (!env_var[1] && (unsigned long)pos != ft_strlen(arg)))
		return (0);
	new = ft_lstnew(env_var);
	if (!new)
		return (1);
	if (!*env_lst)
		*env_lst = new;
	else
		ft_lstadd_back(env_lst, new);
	return (0);
}

int	check_valid_env_var_name(char *str, int pos)
{
	int	i;

	if (pos <= 0)
		return (1);
	if (pos == 1 && str[0] == '?')
		return (0);
	i = -1;
	while (++i < pos)
	{
		if ((!i && (ft_isdigit(str[i]) && str[i] != '_'))
			|| (!ft_isdigit(str[i])
				&& !ft_isalpha(str[i]) && !is_valid_varname_char(str[i])))
			return (1);
	}
	return (0);
}

static int	is_valid_varname_char(char c)
{
	if (c != '_' && c != '%')
		return (0);
	return (1);
}
