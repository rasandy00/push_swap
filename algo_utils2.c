/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 08:59:49 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/10 10:38:44 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sort_3a(t_list **list_a)
{
	t_list	*ranked;
	t_list	*a;

	a = *list_a;
	ranked = list_to_rank(&a);
	if (len_list(&a) < 3 && !check_sort(&a))
		return (sa(&a), free_list(&ranked));
	if (check_sort(list_a))
		return (free_list(&ranked));
	else if (ranked->val == 2 && val_last_list(&ranked) == 3)
		return (sa(list_a), free_list(&ranked));
	else if (ranked->val == 2 && val_last_list(&ranked) == 1)
		return (rra(list_a), free_list(&ranked));
	else if (ranked->val == 3 && val_last_list(&ranked) == 2)
		return (ra(list_a), free_list(&ranked));
	else if (ranked->val == 1 && val_last_list(&ranked) == 2)
		return (ra(list_a), free_list(&ranked), sort_3a(list_a));
	else if (ranked->val == 3 && val_last_list(&ranked) == 1)
		return (sa(list_a), free_list(&ranked), sort_3a(list_a));
}

void	sort_3b(t_list **list_b)
{
	t_list	*b;
	t_list	*ranked;

	b = *list_b;
	ranked = list_to_rank(&b);
	if (len_list(&b) < 3 && !check_reverse_sort(&b))
		return (sb(&b), free_list(&ranked));
	if (check_reverse_sort(list_b))
		return (free_list(&ranked));
	else if (ranked->val == 2 && val_last_list(&ranked) == 3)
		return (rrb(list_b), free_list(&ranked));
	else if (ranked->val == 2 && val_last_list(&ranked) == 1)
		return (rb(list_b), free_list(&ranked));
	else if (ranked->val == 1 && val_last_list(&ranked) == 2)
		return (rb(list_b), free_list(&ranked));
	else if (ranked->val == 1 && val_last_list(&ranked) == 3)
		return (sb(list_b), free_list(&ranked), sort_3b(list_b));
	else if (ranked->val == 3 && val_last_list(&ranked) == 2)
		return (rrb(list_b), free_list(&ranked), sort_3b(list_b));
}

t_list	*join_list(t_list **base, t_list **to_join)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	a = *base;
	b = *to_join;
	tmp = b;
	while (to_join != NULL)
	{
		a = add_list_first(&a, b->val);
		b = b->next;
	}
	if (tmp)
		free (tmp);
	return (a);
}

int	index_of_max(t_list **list)
{
	int		index;
	int		len;
	t_list	*a;

	index = 0;
	len = len_list(list);
	a = list_to_rank(list);
	while (a->next != NULL)
	{
		index++;
		if (a->val == len)
			break ;
		a = a->next;
	}
	free_list(&a);
	return (index);
}

int	index_of_min(t_list **list)
{
	int		index;
	t_list	*a;

	a = list_to_rank(list);
	index = 0;
	while (a != NULL)
	{
		index++;
		if (a->val == 1)
			break ;
		a = a->next;
	}
	free_list(&a);
	return (index);
}
