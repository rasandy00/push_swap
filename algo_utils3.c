/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:38:20 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/10 10:39:04 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_of_median(t_list **list)
{
	t_list	*a;
	int		len;
	int		index;

	index = 0;
	a = list_to_rank(list);
	len = len_list(&a);
	while (a != NULL)
	{
		index++;
		if (a->val == len / 2)
			break ;
		a = a->next;
	}
	free_list(&a);
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
