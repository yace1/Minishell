/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:53:53 by dfarhi            #+#    #+#             */
/*   Updated: 2022/05/31 10:43:05 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_LST_H
# define ENV_LST_H

# include "expanded.h"

# include <stdlib.h>

// TEST
# include <stdio.h>

t_list	*create_env_list(char **envp);
int		env_export(t_list **env_lst, char *arg);
int		env_update_value(t_list *env_lst, char *arg, int pos);
int		check_valid_env_var_name(char *str, int pos);
t_list	*env_is_in_lst(t_list *env_lst, char *arg, int pos);
void	free_env_lst_content(void *content);
void	print_env_list(void *content);
int		set_exit_status(t_list **env, int status);
char	**envlst_to_envp(t_list *env);

#endif
