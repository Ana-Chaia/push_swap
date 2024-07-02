/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:27:21 by anacaro5          #+#    #+#             */
/*   Updated: 2024/07/02 20:23:58 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_to_b(t_info *info)
{
	t_swap	*current;
	int		middle_index;
	int		len_a;
	int		sum;

	len_a = get_stack_size(info->stack_a);
	while (len_a > 3)
	{
		len_a = get_stack_size(info->stack_a);
		if (len_a == 3)
			break ;
		sum = 0;
		current = info->stack_a;
		while (current)
		{
			sum += current->index;
			current = current->next;
		}
		middle_index = sum / len_a;
		current = info->stack_a;
		if (current->index <= middle_index)
			push_b(&info->stack_a, &info->stack_b);
		else
			rotate_a(&(info->stack_a));
	}
}

/* void	all_to_b(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*current;
	int		middle_index;
	int		len_a;
	int		sum;

	len_a = get_stack_size(*stack_a);
	while (len_a > 3)
	{
		len_a = get_stack_size(*stack_a);
		if (len_a == 3)
			break ;
		sum = 0;
		current = *stack_a;
		while (current)
		{
			sum += current->index;
			current = current->next;
		}
		middle_index = sum / len_a;
		current = *stack_a;
		if (current->index <= middle_index)
			push_b(stack_a, stack_b);
		else
			rotate_a(&(*stack_a));
	}
} */

void	moving_to_a(t_info *info, t_swap *cheap_node)
{
	if (info->stack_b->index == cheap_node->index
		&& total_moves_each(info->stack_b) == 0)
	{
		push_a(&info->stack_a, &info->stack_b);
	}
	if (cheap_node->cost_a != cheap_node->cost_b)
	{
		work_a(info, cheap_node->index);
		work_b(info, cheap_node->index);
	}
	else
		if (info->stack_a && info->stack_b)
			work_both(info);
}

void	work_a(t_info *info, int index)
{
	if (index < 0)
		reverserotate_a(&info->stack_a);
	if (index > 0)
		rotate_a(&info->stack_a);
}

void	work_b(t_info *info, int index)
{
	if (index < 0)
		reverserotate_b(&info->stack_b);
	if (index > 0)
		rotate_b(&info->stack_b);
}

void	work_both(t_info *info)
{
	int	total_moves;

	total_moves = total_moves_each(info->stack_b);
	if (total_moves < 0)
		reverserotate_ab(info);
	if (total_moves > 0)
		rotate_ab(info);
}