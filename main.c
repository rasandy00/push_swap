/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:21:38 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/10 17:57:57 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	t_list	*b;

	a = *list_a;
	b = *list_b;
	if (a == NULL || b == NULL)
		return ;
	a = reverse_rotate(&a);
	b = reverse_rotate(&b);
	write (1, "rrr\n", 4);
	*list_a = a;
	*list_b = b;
}

long long	ft_atol(const char *s)
{
	long long	nb;
	int			i;

	nb = 0;
	i = 0;
	i += (s[i] == '-' || s[i] == '+');
	while (s[i] <= '9' && s[i] >= '0')
	{
		nb = (nb * 10) + (s[i] - '0');
		i++;
	}
	if (s[0] == '-')
		return (-nb);
	return (nb);
}

int	check_max(const char **av, int ac)
{
	int	i;
	int	a;

	a = 1;
	i = 0;
	while (ac > a)
	{
		i = 0;
		while (av[a][i])
		{
			while (ft_isspace(av[a][i]))
				i++;
			if ((av[a][i] == '-' || av[a][i] == '+')
				|| ft_isdigit(av[a][i]))
			{
				i += (av[a][i] == '+');
				if (ft_atoi(&av[a][i]) != ft_atol(&av[a][i]))
					return (1);
				i += len_of_int(ft_atoi(&av[a][i]));
			}
		}
		a++;
	}
	return (0);
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
		return (write(1, "Error\n", 6), free_list(&list_a), 0);
	if (list_is_unic(&list_a) || check_sort(&list_a))
		return (free_list(&list_a), 0);
	if (check_max(av, ac))
		return (free_list(&tmp), 0);
	len = len_list(&list_a);
	list_a = list_to_rank(&list_a);
	while (len > 3)
	{
		step1(&list_a, &list_b);
		len = len_list(&list_a);
	}
	step2(&list_a, &list_b);
	return (free_list(&tmp), 0);
}
