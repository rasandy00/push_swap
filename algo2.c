/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:37:14 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/09 17:00:37 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	step1(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;
	int		pivot;
	int		count;
	int		len;
	
	count = 0;
	a = *list_a;
	b = *list_b;
	len = len_list(list_a);
	pivot = get_index(list_a, index_of_median(list_a));
	while (count < len/2)
	{
		if (len_list(&b) > 1 && b->val < pivot/2 && a->val > pivot)
			rr (&a, &b);
		else if (len_list(&b) > 1 && b->val < pivot/2 && b->next->val > pivot/2)
			rb (&b);
		else if (a->val > pivot)
			ra(&a);
		else
		{
			pb(&a, &b);
			count++;  
		}
	}
	*list_a = a;
	*list_b = b;
}



void	step2(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;
	int		max;
	int		len;
	int		index;

	a = *list_a;
	b = *list_b;
	while (len_list(&b) != 0)
	{
		len = len_list(&b);
		max = max_val(&b);
		while (b->val != max)
		{
			if (index_of_max(&b) < len/2)
				rb(&b);
			else
			 	rrb(&b);	
		}
		pa(&a, &b);
	}
	list_a = &a;
	list_b = &b;
}
