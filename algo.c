/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:25:59 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/04 15:21:56 by andriamr         ###   ########.fr       */
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

int	min_val(t_list **list_a)
{
	t_list	*a;
	t_list	*tmp;
	t_list	*list_rank;
	int		val_min;
	
	a = *list_a;
	val_min = 0;
	list_rank = list_to_rank(&a);
	tmp =list_rank;
	while (list_rank->val != 1)
	{
		list_rank = list_rank->next;
		a = a->next;
	}
	val_min = a->val;
	a =*list_a;
	free_list(&tmp);
	return (val_min);
}

int	median_val(t_list **list_a)
{
	t_list	*a;
	t_list	*tmp;
	t_list	*list_rank;
	int		median;
	int		list_size;

	a = *list_a;
	list_size = len_list(&a);
	median = list_size / 2;
	list_rank = list_to_rank(&a);
	tmp = list_rank;
	while (list_rank->val != median)
	{
		list_rank = list_rank->next;
		a =	a->next;
	}
	median = a->val;
	a =	*list_a;
	free_list(&tmp);
	return (median);
}

void	algo_by3(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;
	int		pivot;
	int		len;

	pivot = 3;
	b = list_to_rank(list_a);
	a = list_to_rank(list_b);
	len = len_list(&a);
	while(len >= 0)
	{
		printf_list(&a,&b);
		if (len_list(&b) == 3)
			break;
		if(a->val > pivot)
			ra(&a);
		else
		 pb(&a, &b);
		len--;
	}
	sort_3b(&b);
	
	printf_list(&a,&b);

}

