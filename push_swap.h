/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:14:25 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/11 10:01:49 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				val;
	struct s_list	*next;
}	t_list;

int				ft_digit(int c);
int				ft_isspace(char space);
int				ft_atoi(const char *s);
long long		ft_atol(const char *s);
int				len_of_int(int nb);
int				count_nbr_in_str(int ac, const char **av);
t_list			*take_nbr(const char **argv, int argc);
t_list			*creat_list(int new_val);
void			add_list_last(t_list **list, int add);
t_list			*add_list_at(t_list **list, int add, int index);
t_list			*add_list_first(t_list **list, int add);
t_list			*remove_list_first(t_list **list);
t_list			*remove_list_last(t_list **nbr);
void			free_list(t_list **nbr);
int				len_list(t_list **list);
int				val_last_list(t_list **list);
int				list_rank(t_list **list, int val);
t_list			*list_to_rank(t_list **list);
int				max_val(t_list **list_a);
int				index_of_max(t_list **list);
int				index_of_min(t_list **list_a);
int				index_of_median(t_list **list);
int				get_index(t_list **list, int index);
t_list			*swap_fisrt(t_list **list);
void			push_list(t_list **list_remove, t_list **list_add);
t_list			*rotate(t_list **list);
t_list			*reverse_rotate(t_list **list);
void			sort_3a(t_list **list_a);
int				chek_error_argv(int argc, const char **argv);
int				check_repeat(t_list **nbr);
int				check_max(const char **av, int ac);
int				check_sort(t_list **list_a);
int				list_is_unic(t_list **list);
void			sa(t_list **list_a);
void			sb(t_list **list_b);
void			ss(t_list **list_a, t_list **list_b);
void			pa(t_list **list_a, t_list **list_b);
void			pb(t_list **list_a, t_list **list_b);
void			ra(t_list **list_a);
void			rb(t_list **list_b);
void			rr(t_list **list_a, t_list **list_b);
void			rra(t_list **list_a);
void			rrb(t_list **list_b);
void			rrr(t_list **list_a, t_list **list_b);
void			step1(t_list **list_a, t_list **list_b);
void			step2(t_list **list_a, t_list **list_b);

#endif