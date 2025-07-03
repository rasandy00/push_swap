/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:17:11 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/03 11:32:21 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*take_nbr(const char **argv, int argc)
{
	int		i;
	int		ac;
	t_list	*nbr;

	i = 0;
	ac = 1;
	nbr = NULL;
	while (argc > ac)
	{
		i = 0;
		while (argv[ac][i])
		{
			while (ft_isspace(argv[ac][i]))
				i++;
			if ((argv[ac][i] == '-' || argv[ac][i] == '+')
				|| ft_isdigit(argv[ac][i]))
			{
				i += (argv[ac][i] == '+');
				add_list_last(&nbr, ft_atoi(&argv[ac][i]));
				i += len_of_int(ft_atoi(&argv[ac][i]));
			}
		}
		ac++;
	}
	return (nbr);
}
