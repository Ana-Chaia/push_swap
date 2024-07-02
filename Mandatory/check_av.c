/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:49:01 by anacaro5          #+#    #+#             */
/*   Updated: 2024/06/18 14:52:03 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end_push_swap(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_isnum(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

void	check_av(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 2)
		exit(EXIT_FAILURE);
	while (++i < ac)
	{
		if ((!av[i][0] || !ft_isnum(av[i])) || (ft_atol(av[i]) > INT_MAX)
			|| (ft_atol(av[i]) < INT_MIN))
			end_push_swap();
		j = i + 1;
		while (j < ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j++]))
				end_push_swap();
		}
	}
}
