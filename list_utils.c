/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:54:37 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/10 14:53:32 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_list(t_list **list)
{
	t_list	*first;
	int		len;

	len = 0;
	first = *list;
	while (first != NULL)
	{
		first = first->next;
		len++;
	}
	return (len);
}

int	index_of_milist(t_list **list)
{
	int		len;
	t_list	*first;
	int		val;

	len = 0;
	first = *list;
	while (first != NULL)
	{
		first = first->next;
		len++;
	}
	val = len / 2;
	return (val);
}

int	val_last_list(t_list **list)
{
	t_list	*a;
	int		val;

	a = *list;
	while (a != NULL)
	{
		val = a->val;
		a = a->next;
	}
	return (val);
}

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

int	max_val(t_list **list_a)
{
	t_list	*a;
	t_list	*list_rank;
	t_list	*tmp;
	int		list_size;
	int		val_max;

	val_max = 0;
	list_rank = NULL;
	a = *list_a;
	list_rank = list_to_rank(list_a);
	list_size = len_list(list_a);
	tmp = list_rank;
	while (list_rank->val != list_size)
	{
		list_rank = list_rank->next;
		a = a->next;
	}
	val_max = a->val;
	a = *list_a;
	free_list(&tmp);
	return (val_max);
}
