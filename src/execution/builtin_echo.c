/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:01:58 by dfarhi            #+#    #+#             */
/*   Updated: 2022/06/09 12:15:42 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	builtin_echo(t_pipe pipe)
{
	int	nl;
	int	i;

	nl = 1;
	i = 0;
	while (pipe.cmdargs[++i])
	{
		if (!ft_strncmp(pipe.cmdargs[i], "-n", 3))
			nl = 0;
		else
		{
			if (i - !nl > 1)
				printf(" ");
			printf("%s", pipe.cmdargs[i]);
		}
	}
	if (nl)
		printf("\n");
	return (0);
}
