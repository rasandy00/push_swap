/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:21:38 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/09 14:39:23 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	printf_list(t_list **list1, t_list **list2)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = *list1;
	list_b = *list2;
	while (list_a || list_b)
	{
		if (list_a)
		{
			printf("%d ", list_a->val);
			list_a = list_a->next;
		}
		printf("---------- ");
		if (list_b)
		{
			printf ("%d", list_b->val);
			list_b = list_b->next;
		}
		printf("\n");
	}
	printf ("*************\n");
}

int	main(int ac, const char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*new;
	int pivot;
	int len = 0;

	list_b = NULL;
	if (chek_error_argv(ac, av))
		return (printf ("Error  argv"), 0);
	list_a = take_nbr(av, ac);
	if (check_repeat(&list_a))
		return (printf ("Error repet ou unic"),free_list(&list_a), 0);
	if (list_is_unic(&list_a))
		return (printf ("un suel chiffre\n"),free_list(&list_a), 0);
	if (check_sort(&list_a))
		return (printf("efa OK"),free_list(&list_a) , 0);
	len = len_list(&list_a);
	list_a = list_to_rank(&list_a);
	while (len > 3)
	{
		step1(&list_a, &list_b);
		len = len_list(&list_a);
	}
	sort_3a(&list_a);
	step2(&list_a, &list_b);
	return (0);
}
