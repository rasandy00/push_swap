/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instriction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:03:24 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/10 15:00:54 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **list_a)
{
	t_list	*a;

	a = *list_a;
	if (a == NULL)
		return ;
	a = swap_fisrt(&a);
	write (1, "sa\n", 3);
	*list_a = a;
}

void	sb(t_list **list_b)
{
	t_list	*b;

	b = *list_b;
	if (b == NULL)
		return ;
	b = swap_fisrt(&b);
	write (1, "sb\n", 3);
	*list_b = b;
}

void	ss(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;

	a = *list_a;
	b = *list_b;
	if (a == NULL || b == NULL)
		return ;
	a = swap_fisrt(&a);
	b = swap_fisrt(&b);
	write (1, "ss\n", 3);
	*list_a = a;
	*list_b = b;
}

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;

	a = *list_a;
	b = *list_b;
	push_list (list_b, list_a);
	write (1, "pa\n", 3);
}

void	rrb(t_list **list_b)
{
	t_list	*b;

	b = *list_b;
	if (b == NULL)
		return ;
	b = reverse_rotate(&b);
	write (1, "rrb\n", 4);
	*list_b = b;
}
