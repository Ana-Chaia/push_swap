/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:11:45 by anacaro5          #+#    #+#             */
/*   Updated: 2024/06/27 15:56:11 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_swap **stack_a)
{
	t_swap	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = (*stack_a)->next;
		(*stack_a)->next = temp;
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_swap **stack_b)
{
	t_swap	*temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = (*stack_b)->next;
		(*stack_b)->next = temp;
		write(1, "sa\n", 3);
	}
}

void	swap_ab(t_info **stackname)
{
	t_swap	*temp;

	if (((*stackname)->stack_a && (*stackname)->stack_a->next)
		&& ((*stackname)->stack_b && (*stackname)->stack_b->next))
	{
		temp = (*stackname)->stack_a;
		(*stackname)->stack_a = (*stackname)->stack_a->next;
		temp->next = (*stackname)->stack_a->next;
		(*stackname)->stack_a->next = temp;
		temp = (*stackname)->stack_b;
		(*stackname)->stack_b = (*stackname)->stack_b->next;
		temp->next = (*stackname)->stack_b->next;
		(*stackname)->stack_b->next = temp;
		write(1, "ss\n", 3);
	}
}
