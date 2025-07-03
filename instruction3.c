/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:45:27 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/03 12:09:10 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rrr(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;

	a = *list_a;
	b = *list_b;
	if (a == NULL || b == NULL)
		return ;
	a = reverse_rotate(&a);
	b = reverse_rotate(&b);
	write (1, "rrr\n", 4);
	*list_a = a;
	*list_b = b;
}
