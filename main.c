/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:21:38 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/07 11:56:32 by andriamr         ###   ########.fr       */
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
	new = NULL;
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
	// printf_list(&list_a,&list_b);
	len = len_list(&list_a);
	while (len > 3)
	{
		step1(&list_a, &list_b);
		len = len_list(&list_a);
	}
	sort_3a(&list_a);
	// printf_list(&list_a,&list_b);
	step2(&list_a, &list_b);
	// printf ("/**/**/*/*/*/*/*/\n");
	// printf_list(&list_a,&list_b);

	// len = len_list(&list_a);
	// pivot = get_index(&list_a, index_of_median(&list_a));
	// printf("\n%d\n", pivot);
	// free_list(&list_a);
	// free_list(&list_b);
	return (0);
}
