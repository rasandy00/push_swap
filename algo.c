/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:25:59 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/03 13:52:28 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*list_to_rank(t_list **list)
{
	t_list	*a;
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*new;

	a = *list;
	tmp = a;
	tmp2 = tmp;
	new = NULL;
	while (a != NULL)
	{
		tmp = tmp2;
		add_list_last(&new, list_rank(&tmp, a->val));
		a = a->next;
	}
	return (new);
}

void	algo1(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		pivot;

	i = 0;
	b = *list_b;
	a = *list_a;
	pivot = val_last_list(&a);
	while (a->val != pivot)
	{
		if (a->val > pivot)
			ra(&a);
		else
			pb (&a, &b);
	}
	if (!check_sort(&a))
	{
		i++;
		algo1 (&a, &b);
	}
	while (i-- != 0)
		pa (&a, &b);
	if (check_reverse_sort(&b))
	{
		while (b != NULL)
			pa (&a, &b);
	}
}
