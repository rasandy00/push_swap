/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:36:30 by andriamr          #+#    #+#             */
/*   Updated: 2025/06/29 15:32:05 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap_fisrt(t_list **list)
{
	t_list	*first;
	int		tmp;

	first = *list;
	tmp = first->val;
	first->val = first->next->val;
	first->next->val = tmp;
	return (first);
}

void	push_list(t_list **list_remove, t_list **list_add)
{
	t_list	*remove;

	remove = *list_remove;
	if (remove == NULL)
		return ;
	*list_add = add_list_first(list_add, remove->val);
	*list_remove = remove_list_first(&remove);
}

t_list	*rotate(t_list **list)
{
	t_list	*first;
	int		tmp;

	first = *list;
	tmp = first->val;
	first = remove_list_first(&first);
	add_list_last(&first, tmp);
	return (first);
}

t_list	*reverse_rotate(t_list **list)
{
	t_list	*first;
	int		tmp;

	first = *list;
	while (first->next != NULL)
		first = first->next;
	tmp = first->val;
	first = *list;
	first = remove_list_last(&first);
	first = *list;
	first = add_list_first(&first, tmp);
	return (first);
}
