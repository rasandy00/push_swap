/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:21:38 by andriamr          #+#    #+#             */
/*   Updated: 2025/06/29 15:33:49 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	printf_list(t_list **list1, t_list **list2)
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
}

int	main(int ac, const char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*tmpa;
	t_list	*tmpb;

	list_b = NULL;
	if (chek_error_argv(ac, av))
		return (printf ("Error"), 0);
	list_a = take_nbr(av, ac);
	tmpa = list_a;
	if (check_repeat(&list_a))
		return (printf ("Error"), 0);
	printf_list(&list_a, &list_b);
	printf("///////////\n");
	push_list(&list_a, &list_b);
	printf_list(&list_a, &list_b);
	free_list(&list_a);
	free_list(&list_b);
	return (0);
}
