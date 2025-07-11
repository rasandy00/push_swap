/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 07:37:14 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/11 10:01:49 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	suplement(t_list **list_a, t_list **list_b, int len, int pivot)
{
	int		count;
	t_list	*a;
	t_list	*b;

	a = *list_a;
	b = *list_b;
	count = 0;
	while (count < len / 2)
	{
		if (len_list(&b) > 1 && b->val < pivot / 2 && a->val > pivot)
			rr (&a, &b);
		else if (len_list(&b) > 1 && b->val < pivot / 2
			&& b->next->val > pivot / 2)
			rb (&b);
		else if (a->val > pivot)
			ra(&a);
		else
		{
			pb(&a, &b);
			count++;
		}
	}
	*list_a = a;
	*list_b = b;
}

void	step1(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;
	int		pivot;
	int		count;
	int		len;

	count = 0;
	a = *list_a;
	b = *list_b;
	len = len_list(list_a);
	pivot = get_index(list_a, index_of_median(list_a));
	suplement(&a, &b, len, pivot);
	*list_a = a;
	*list_b = b;
}

static void	suplement2(t_list **list_a, t_list **list_b, int max, int len)
{
	t_list	*a;
	t_list	*b;
	int		count;

	a = *list_a;
	b = *list_b;
	count = 0;
	while (b->val != max)
	{
		if (b->val == max - 1 && count != 1)
		{
			pa(&a, &b);
			count++;
		}
		if (index_of_max(&b) < len / 2)
			rb(&b);
		else
			rrb(&b);
	}
	*list_a = a;
	*list_b = b;
}

void	step2(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;
	int		max;
	int		len;

	a = *list_a;
	b = *list_b;
	sort_3a(&a);
	while (len_list(&b) != 0)
	{
		len = len_list(&b);
		max = max_val(&b);
		suplement2(&a, &b, max, len);
		pa(&a, &b);
		if (a->val == a->next->val + 1)
			sa(&a);
	}
	free_list(&a);
}

int	len_digit(char *argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (ft_isspace(argv[i]))
		i++;
	if (argv[i] == '-' || argv[i] == '+')
	{
		count++;
		i++;
	}
	while (ft_digit(argv[i]))
	{
		i++;
		count++;
	}
	return (count);
}
