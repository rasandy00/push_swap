/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:21:38 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/10 10:49:49 by andriamr         ###   ########.fr       */
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
	t_list	*tmp;
	int		len;

	list_b = NULL;
	list_a = take_nbr(av, ac);
	tmp = list_a;
	if (chek_error_argv(ac, av) || check_repeat(&list_a))
		return (printf ("Error"), free_list(&list_a), 0);
	if (list_is_unic(&list_a))
		return (printf ("un suel chiffre\n"), free_list(&list_a), 0);
	if (check_sort(&list_a))
		return (printf("efa OK"), free_list(&list_a), 0);
	len = len_list(&list_a);
	list_a = list_to_rank(&list_a);
	free_list(&tmp);
	while (len > 3)
	{
		step1(&list_a, &list_b);
		len = len_list(&list_a);
	}
	step2(&list_a, &list_b);
	free_list(&list_a);
	return (0);
}
