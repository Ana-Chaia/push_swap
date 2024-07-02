/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:03:34 by anacaro5          #+#    #+#             */
/*   Updated: 2024/07/02 20:02:22 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_swap **stack_a)
{
	t_swap	*first;
	t_swap	*last;

	if (*stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		last = last_value(*stack_a);
		*stack_a = first->next;
		first->next = NULL;
		last->next = first;
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_swap **stack_b)
{
	t_swap	*first;
	t_swap	*last;

	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		last = last_value(*stack_b);
		*stack_b = first->next;
		first->next = NULL;
		last->next = first;
		write(1, "rb\n", 3);
	}
}

void	rotate_ab(t_info *stackname)
{
	t_swap	*first;
	t_swap	*last;

	if ((stackname->stack_a && stackname->stack_a->next)
		&& (stackname->stack_b && stackname->stack_b->next))
	{
		first = stackname->stack_a;
		last = last_value(stackname->stack_a);
		stackname->stack_a = first->next;
		first->next = NULL;
		last->next = first;
		first = stackname->stack_b;
		last = last_value(stackname->stack_b);
		stackname->stack_b = first->next;
		first->next = NULL;
		last->next = first;
		write(1, "rr\n", 3);
	}
}
