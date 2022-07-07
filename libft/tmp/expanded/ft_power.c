/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:50:00 by dfarhi            #+#    #+#             */
/*   Updated: 2021/11/25 14:52:46 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_power(int nb, int power)
{
	long	res;

	res = 1;
	if (power < 0)
		return (0);
	while (power--)
		res *= nb;
	return (res);
}
