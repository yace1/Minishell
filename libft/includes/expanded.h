/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfarhi <dfarhi@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:29:36 by dfarhi            #+#    #+#             */
/*   Updated: 2022/05/27 14:42:23 by davifah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDED_H
# define EXPANDED_H

# include "libft.h"

char	ft_baselen(long nbr, char *base);
char	*ft_itoa_base(long nbr, char *base);
long	ft_power(int nb, int power);
int		ft_isspace(char c);
t_list	*ft_lstget_index(t_list *lst, int index);
t_list	*ft_lstremove_index(t_list **lst, int index);
char	*ft_strjoin3(char const *s1, char const *s2, char const *s3);

#endif
