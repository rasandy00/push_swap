/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 08:59:49 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/10 14:53:09 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	index_of_max(t_list **list)
{
	int		index;
	int		len;
	t_list	*a;
	t_list	*tmp;

	index = 0;
	len = len_list(list);
	a = list_to_rank(list);
	tmp = a;
	while (a->next != NULL)
	{
		index++;
		if (a->val == len)
			break ;
		a = a->next;
	}
	free_list(&tmp);
	return (index);
}

int	index_of_min(t_list **list)
{
	int		index;
	t_list	*a;
	t_list	*tmp;

	a = list_to_rank(list);
	tmp = a;
	index = 0;
	while (a != NULL)
	{
		index++;
		if (a->val == 1)
			break ;
		a = a->next;
	}
	free_list(&tmp);
	return (index);
}

int	index_of_median(t_list **list)
{
	t_list	*a;
	t_list	*tmp;
	int		len;
	int		index;

	index = 0;
	a = list_to_rank(list);
	tmp = a;
	len = len_list(&a);
	while (a != NULL)
	{
		index++;
		if (a->val == len / 2)
			break ;
		a = a->next;
	}
	free_list(&tmp);
	return (index);
}

int	get_index(t_list **list, int index)
{
	t_list	*a;
	int		i;

	i = 0;
	a = *list;
	while (i < index -1)
	{
		a = a->next;
		i++;
	}
	i = a->val;
	return (i);
}
