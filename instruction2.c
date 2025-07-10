/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:26:22 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/10 15:01:07 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;

	a = *list_a;
	b = *list_b;
	push_list(list_a, list_b);
	write(1, "pb\n", 3);
}

void	ra(t_list **list_a)
{
	t_list	*a;

	a = *list_a;
	if (a == NULL)
		return ;
	a = rotate(&a);
	write(1, "ra\n", 3);
	*list_a = a;
}

void	rb(t_list **list_b)
{
	t_list	*b;

	b = *list_b;
	if (b == NULL)
		return ;
	b = rotate(&b);
	write(1, "rb\n", 3);
	*list_b = b;
}

void	rr(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;

	a = *list_a;
	b = *list_b;
	if (a == NULL || b == NULL)
		return ;
	a = rotate(&a);
	b = rotate(&b);
	write(1, "rr\n", 3);
	*list_a = a;
	*list_b = b;
}

void	rra(t_list **list_a)
{
	t_list	*a;

	a = *list_a;
	if (a == NULL)
		return ;
	a = reverse_rotate(&a);
	write (1, "rra\n", 4);
	*list_a = a;
}
