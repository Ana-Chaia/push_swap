/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:53:51 by anacaro5          #+#    #+#             */
/*   Updated: 2024/07/02 20:00:20 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverserotate(t_swap **stackname)
{
	t_swap	*last;
	t_swap	*prev;

	if (*stackname && (*stackname)->next)
	{
		last = *stackname;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stackname;
		*stackname = last;
	}
}

void	reverserotate_a(t_swap **stack_a)
{
	t_swap	*last;
	t_swap	*prev;

	if (*stack_a && (*stack_a)->next)
	{
		prev = NULL;
		last = *stack_a;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
		write(1, "rra\n", 4);
	}
}

void	reverserotate_b(t_swap **stack_b)
{
	t_swap	*last;
	t_swap	*prev;

	if (*stack_b && (*stack_b)->next)
	{
		prev = NULL;
		last = *stack_b;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
		write(1, "rrb\n", 4);
	}
}

void	reverserotate_ab(t_info *stackname)
{
	if ((stackname->stack_a && stackname->stack_a->next)
		&& (stackname->stack_b && stackname->stack_b->next))
	{
		reverserotate(&stackname->stack_a);
		reverserotate(&stackname->stack_b);
		write(1, "rrr\n", 4);
	}
}
