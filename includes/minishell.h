/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:13:36 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/02 19:46:58 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "expanded.h"
# include "get_next_line.h"
# include "parsing.h"
# include "execution.h"
# include "env_lst.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <sys/uio.h>

t_list	*parsing(char *str, t_list *env);

#endif
