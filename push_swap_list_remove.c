/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_remove.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:23:48 by andriamr          #+#    #+#             */
/*   Updated: 2025/06/29 15:30:58 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*remove_list_first(t_list **list)
{
	t_list	*first;
	t_list	*tmp;

	first = *list;
	tmp = first;
	if (tmp == NULL)
		return (tmp);
	first = first->next;
	free (tmp);
	return (first);
}

t_list	*remove_list_last(t_list **nbr)
{
	t_list	*list;
	t_list	*tmp;

	list = *nbr;
	if (list == NULL)
		return (list);
	while (list->next->next != NULL)
		list = list->next;
	tmp = list->next;
	list->next = NULL;
	free (tmp);
	return (list);
}

void	free_list(t_list **list)
{
	t_list	*nbr;
	t_list	*tmp;

	nbr = *list;
	while (nbr != NULL)
	{
		tmp = nbr;
		nbr = nbr->next;
		remove_list_first(&tmp);
	}
}
