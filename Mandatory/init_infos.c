/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:58:57 by anacaro5          #+#    #+#             */
/*   Updated: 2024/07/05 19:04:22 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_order(char **av)
{
	int		x;
	int		y;
	char	*temp;

	x = 0;
	while (av[x])
	{
		y = x + 1;
		while (av[y])
		{
			if (ft_atol(av[x]) > ft_atol(av[y]))
			{
				temp = av[x];
				av[x] = av[y];
				av[y] = temp;
			}
			y++;
		}
		x++;
	}
}

void	init_index(t_swap *stack_a, char **av)
{
	int		order_posi;
	t_swap	*current;

	order_posi = 1;
	current = stack_a;
	find_order(av);
	while (av[order_posi] && current)
	{
		if (ft_atol(av[order_posi]) == current->value)
		{
			current->index = order_posi;
			current = current->next;
			order_posi = 0;
		}
		order_posi++;
	}
}

void	init_stack_posi(t_swap *stackname)
{
	int	current_posi;

	current_posi = 0;
	while (stackname)
	{
		stackname->posi = current_posi;
		stackname = stackname->next;
		current_posi++;
	}
}

// void	init_max_min(t_swap *stackname)
// {
// 	if (stackname == NULL)
// 		return ;

// 	stackname->min_value = stackname->value;
// 	stackname->max_value = stackname->value;

// 	while (stackname)
// 	{
// 		if (stackname->value < stackname->min_value)
// 			stackname->min_value = stackname->value;
// 		if (stackname->value > stackname->max_value)
// 			stackname->max_value = stackname->value;
// 		stackname = stackname->next;
// 	}
// }

void	init_target_posi(t_info *stackname)
{
	t_swap	*current_a;
	t_swap	*current_b;
	t_swap	*find_min;
	int		size;

	current_b = stackname->stack_b;
	init_stack_posi(stackname->stack_a);
	while (current_b)
	{
		current_b->target_posi = -1;
		current_a = stackname->stack_a;
		find_min = stackname->stack_a;
		size = get_stack_size(stackname->stack_a)
			+ get_stack_size(stackname->stack_b);
		while (current_a)
		{
			if (current_b->index < current_a->index && current_a->index <= size)
			{
				current_b->target_posi = current_a->posi;
				size = current_a->index;
			}
			if (current_a->index < find_min->index)
				find_min = current_a;
			current_a = current_a->next;
		}
		if (current_b->target_posi == -1)
			current_b->target_posi = find_min->posi;
		current_b = current_b->next;
	}
}


