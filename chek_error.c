/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:37:49 by andriamr          #+#    #+#             */
/*   Updated: 2025/06/27 14:42:32 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chek_error_argv(int argc, const char **argv)
{
	int	i;
	int	ac;

	ac = 1;
	if (argc <= 1)
		return (1);
	while (argc > ac)
	{
		i = 0;
		while (argv[ac][i])
		{
			if ((ft_isdigit(argv[ac][i]) || ft_isspace(argv[ac][i]))
				|| ((argv[ac][i] == '-' && (i == 0))
				|| (ft_isspace(argv[ac][i - 1])
				&& ft_isdigit(argv[ac][i + 1])))
				|| ((argv[ac][i] == '+' && (i == 0))
				|| (ft_isspace(argv[ac][i - 1])
				&& ft_isdigit(argv[ac][i + 1]))))
				i++;
			else
				return (1);
		}
		ac++;
	}
	return (0);
}

int	check_repeat(t_list **nbr)
{
	t_list	*to_cmp;
	t_list	*all;

	to_cmp = *nbr;
	while (to_cmp != NULL)
	{
		all = to_cmp->next;
		while (all != NULL)
		{
			if (to_cmp->val == all->val)
				return (1);
			all = all->next;
		}
		to_cmp = to_cmp->next;
	}
	return (0);
}
