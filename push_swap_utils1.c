/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:14:46 by andriamr          #+#    #+#             */
/*   Updated: 2025/07/10 17:56:54 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

int	ft_isspace(char space)
{
	return ((space >= 9 && space <= 13) || space == 32);
}

int	ft_atoi(const char *s)
{
	long	nb;
	int		i;
	char	*str;

	nb = 0;
	i = 0;
	str = (char *)s;
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

int	len_of_int(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	count++;
	return (count);
}

int	count_nbr_in_str(int ac, const char **av)
{
	int	count;
	int	j;
	int	i;

	j = 1;
	count = 0;
	while (ac > j)
	{
		i = 0;
		while (av[j][i])
		{
			if (ft_isdigit(av[j][i])
				&& (ft_isspace(av[j][i + 1])
				|| av[j][i + 1] == '\0'))
				count++;
			i++;
		}
		j++;
	}
	return (count);
}
