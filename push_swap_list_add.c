/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_add.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:15:38 by andriamr          #+#    #+#             */
/*   Updated: 2025/06/29 13:27:39 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*creat_list(int new_val)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->val = new_val;
	new_list->next = NULL;
	return (new_list);
}

t_list	*add_list_first(t_list **list, int add)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *list;
	new = creat_list(add);
	new->next = tmp;
	*list = new;
	return (new);
}

void	add_list_last(t_list **list, int add)
{
	t_list	*last;
	t_list	*first;

	last = creat_list(add);
	if (*list == NULL)
	{
		*list = last;
		return ;
	}
	first = *list;
	while (first->next != NULL)
		first = first->next;
	first->next = last;
	last->next = NULL;
}

t_list	*add_list_at(t_list **list, int add, int index)
{
	t_list	*first;
	t_list	*new;
	int		i;

	i = 0;
	if (!list)
		return (NULL);
	if (index == 0)
		add_list_first(list, add);
	first = *list;
	while (index - 1 > i && first != NULL)
	{
		first = first->next;
		i++;
	}
	if (first == NULL)
		return (first);
	new = creat_list(add);
	new->next = first->next;
	first->next = new;
	return (first);
}
