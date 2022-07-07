/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:00:12 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/06/29 22:26:14 by dfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define RESET	"\x1B[0m"

typedef struct s_data{
	struct s_list	*arg_lst;
}	t_data;

void	display_banner(void);
char	*make_prompt(char **env);
/*------------------------------------------------------------*/
int		check_error(char *str, t_list *env);
int		redir_is_alone(t_list *lst, t_list *env);
int		quote_error_nb(char *str);
int		skip_quote(char *str, char c, int index);
int		arg_size(char *str);
char	*skip_space(char *str, int size);
char	*nrml_arg(t_list *tmp, char *str, t_list **lst, t_list *env);
char	*fill_quote(t_list *arg, char *str, t_list **lst, t_list *env);
char	*fill_s_quote(t_list *arg, char *str, t_list **lst, t_list *env);
char	*check_redir(t_list *tmp, char *str, t_list **lst);
char	*check_env_var(char *str, t_list *arg, t_list *env);
int		ft_isalnum_under(int c, int index);
char	*strjoin_free(char *s1, char *s2, int is_malloc);
int		check_nxt_char(char *str);
/*------------------------------------------------------------*/
void	print_linked_lst(t_list *lst);
void	add_back_new_lst(t_list **lst);
void	add_content_last(t_list *arg, char *str, int is_malloc);
int		free_lst(t_list *main_lst);
t_list	*clear_lst(t_list *lst);
t_list	*get_previous(t_list *main_lst, t_list *curr);
void	iterate_clean_lst(t_list *tmp, t_list *lst, t_list *to_free);

#endif

// while (1)
// {
// 	usleep(1000);
// 	printf("%d\n", getpid());
// }

// typedef struct s_lst{
// 	struct s_args	*arg;
// 	struct s_lst	*next;
// }	t_lst;

// typedef struct s_args{
// 	char			*str;
// 	struct s_args	*next;
// }	t_arg;
