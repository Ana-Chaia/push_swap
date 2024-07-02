/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:31:18 by anacaro5          #+#    #+#             */
/*   Updated: 2024/07/02 20:09:52 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_costs(t_info *stackname)
{
	t_swap	*current_a;
	t_swap	*current_b;

	current_b = stackname->stack_b;
	while (current_b)
	{
		current_a = stackname->stack_a;
		cost_a_n_b(current_a, current_b, 'b', current_b->posi);
		while (current_a)
		{
			if (current_b->posi == current_a->posi)
				cost_a_n_b(current_a, current_b, 'a', current_a->posi);
			current_a = current_a->next;
		}
		current_b = current_b->next;
	}
}

void	cost_a_n_b(t_swap *stack_a, t_swap *stack_b, char stack_id, int posi)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);

	if (stack_id == 'a')
	{
		if (posi <= (len_a / 2))
			stack_b->cost_a = posi;
		else
			stack_b->cost_a = len_a - posi;
	}
	else
	{
		if (posi <= (len_b / 2))
			stack_b->cost_b = posi;
		else
			stack_b->cost_b = len_b - posi;
	}
}

int	total_moves_each(t_swap *stackname)
{
	int		moves;

	return (moves = abs(stackname->cost_a)
		+ abs(stackname->cost_b));
}

t_swap	*find_smallest_move(t_swap *stackname)
{
	t_swap	*current_node;
	t_swap	*cheapest_node;
	int		smallest_move;
	int		current_move;

	smallest_move = INT_MAX;
	current_node = stackname;
	cheapest_node = NULL;
	while (current_node)
	{
		current_move = total_moves_each(current_node);
		if (current_move < smallest_move)
		{
			smallest_move = current_move;
			cheapest_node = current_node;
		}
		current_node = current_node->next;
	}
	return (cheapest_node);
}




