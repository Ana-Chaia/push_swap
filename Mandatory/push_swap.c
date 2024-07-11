/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:54:22 by anacaro5          #+#    #+#             */
/*   Updated: 2024/07/11 17:02:56 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	sort_two(t_swap *stackname)
{
	if (stackname->value > stackname->next->value)
	{
		write(1, "sa\n", 3);
		return (0);
	}
	else
		return (1);
}

void	sort_three(t_info *stackname)
{
	stackname->max_index = get_max(stackname->stack_a);
	if (stackname->stack_a->value == stackname->max_index)
		rotate_a(&(stackname)->stack_a);
	else if (stackname->stack_a->next->value == stackname->max_index)
		reverserotate_a(&(stackname)->stack_a);
	if (stackname->stack_a->value > stackname->stack_a->next->value)
		swap_a(&(stackname)->stack_a);
}

void	sort_a(t_swap **stackname)
{
	int		middle_len;
	int		first_posi;
	t_swap	*temp;

	middle_len = get_stack_size(*stackname) / 2;
	temp = *stackname;
	while (temp)
	{
		if (temp->index == 1)
			first_posi = temp->posi;
		temp = temp->next;
	}
	while ((*stackname)->index != 1)
	{
		if (first_posi <= middle_len)
			rotate_a(stackname);
		else
			reverserotate_a(stackname);
	}
}

void	sort_many(t_info *stackname)
{
	t_swap	*temp;
	t_swap	*cheap_node;

	temp = stackname->stack_b;
	while (temp)
	{
		init_stack_posi(stackname->stack_a);
		init_stack_posi(stackname->stack_b);
		init_target_posi(stackname); //VERIFICAR DEBUG DAQUIIIIIII
		init_costs(stackname);
		cheap_node = find_smallest_move(stackname->stack_b);
		moving_to_a(stackname, cheap_node);
		temp = stackname->stack_b;
	}
	init_stack_posi(stackname->stack_a);
	//print_list(stackname->stack_a);
	sort_a(&(stackname)->stack_a);
}

void	push_swap(t_info *info)
{
	all_to_b(info);
	sort_three(info);
	sort_many(info);
}
