/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:14:25 by andriamr          #+#    #+#             */
/*   Updated: 2025/06/29 15:30:34 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				val;
	struct s_list	*next;
}	t_list;

//utils
int				ft_isdigit(int c);
int				ft_isspace(char space);
int				ft_atoi(const char *s);
void			*ft_calloc(size_t nmemb, size_t size);
int				len_of_int(int nb);
int				count_nbr_in_str(int ac, const char **av);
//list
t_list			*take_nbr(const char **argv, int argc);
t_list			*creat_list(int new_val);
void			add_list_last(t_list **list, int add);
t_list			*add_list_at(t_list **list, int add, int index);
t_list			*add_list_first(t_list **list, int add);
t_list			*remove_list_first(t_list **list);
t_list			*remove_list_last(t_list **nbr);
void			free_list(t_list **nbr);
//algo
t_list			*swap_fisrt(t_list **list);
void			push_list(t_list **list_remove, t_list **list_add);
t_list			*rotate(t_list **list);
t_list			*reverse_rotate(t_list **list);

//chek_error
int				chek_error_argv(int argc, const char **argv);
int				check_repeat(t_list **nbr);

#endif
