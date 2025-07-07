/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:37:14 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/07 11:56:25 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_3a(t_list **list_a)
// {
	// int	i = 0;
	// t_list	*a;
// 
	// a = *list_a;
	// if (a == NULL)
		// return ;
	// if (a->val > a->next->val)
		// sa (&a);
	// list_a = &a;
// }


void	step1(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;
	int		pivot;
	int		count=0;
	int	len =0;
	a = *list_a;
	b = *list_b;
	len = len_list(list_a);
	pivot = get_index(list_a, index_of_median(list_a));
	while (count < len/2)
	{
		if (a->val > pivot)
			ra(&a);
		else
		{
			pb(&a, &b);
			count++;
		}
	// printf_list(&a, &b);
	}
	*list_a = a;
	*list_b = b;
}

void	step2(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;
	int		max = 0;
	int		len;
	int		index = 0;

	a = *list_a;
	b = *list_b;
	len = len_list(&b);
	// printf ("\n len = %d \n", len);

	// index = index_of_max(&b);
	while (len != 0)
	{
		index = index_of_max(&b);
		// printf ("\n ******* index = %d \n", index);
		max =max_val(&b);
		while (b->val != max)
		{
			index = index_of_max(&b);
			// printf ("\n index =%d \n", index);
			if (index < len/2)
				rb(&b);
			else
			 	rrb(&b);
			
		}
		pa(&a, &b);
		len = len_list(&b);
	}
	// printf_list(&a, &b);
	
	list_a = &a;
	list_b = &b;
}
