/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:54:37 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/03 12:14:58 by andriamr         ###   ########.fr       */
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
