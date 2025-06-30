/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:02:37 by andriamr          #+#    #+#             */
/*   Updated: 2025/06/27 14:47:02 by andriamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
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
	while (ft_isdigit(argv[i]))
	{
		i++;
		count++;
	}
	return (count);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (size != 0 && (nmemb != ((nmemb * size) / size)))
		return (NULL);
	str = malloc (nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero (str, nmemb * size);
	return (str);
}
