/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ridicul_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:21:07 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/04 16:24:17 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo_ridicul(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;
	int		len;
	int		index;
 	
	b = NULL;
	a = list_to_rank(list_a);
	len = len_list(&a);
	while (len != 1)
	{
		len = len_list(&a);
		if (len <= 3)
			break;
		tmp = a;
		a = list_to_rank(&a);
		index = index_of_min(&a);
		while (a->val != 1)
		{
			if (len/2 > index)
				ra(&a);
			else
			 	rra(&a);	
		}
		pb(&a, &b);
		if (tmp)
			free_list(&tmp);
	}
	sort_3a(&a);
	while (b != NULL)
		pa(&a, &b);
	free_list(&a);
}
