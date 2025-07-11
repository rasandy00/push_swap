/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:54:40 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/11 16:48:14 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	take_nbr_utils(t_list **nbr, const char **argv, int ac)
{
	int	i;

	i = 0;
	while (argv[ac][i])
	{
		while (ft_isspace(argv[ac][i])
				|| ((argv[ac][i] == '0') && ft_digit(argv[ac][i + 1])))
			i++;
		if ((argv[ac][i] == '-' || argv[ac][i] == '+')
				|| ft_digit(argv[ac][i]))
		{
			i += (argv[ac][i] == '+');
			add_list_last(nbr, (ft_atoi(&argv[ac][i])));
			if (argv[ac][i] == '-' && argv[ac][i + 1] == '0')
			{
				i++;
				while (argv[ac][i] == '0')
					i++;
			}
			i += len_of_int(ft_atoi(&argv[ac][i]));
		}
	}
}

long long	ft_atol(const char *s)
{
	long long	nb;
	int			i;

	nb = 0;
	i = 0;
	i += (s[i] == '-' || s[i] == '+');
	while (s[i] == '0')
		i++;
	while (s[i] <= '9' && s[i] >= '0')
	{
		nb = (nb * 10) + (s[i] - '0');
		i++;
	}
	if (s[0] == '-')
		return (-nb);
	return (nb);
}

t_list	*take_nbr(const char **argv, int argc)
{
	int		i;
	int		ac;
	t_list	*nbr;

	ac = 1;
	nbr = NULL;
	while (argc > ac)
	{
		i = 0;
		take_nbr_utils(&nbr, argv, ac);
		ac++;
	}
	return (nbr);
}
