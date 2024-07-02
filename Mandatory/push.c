/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:13:07 by anacaro5          #+#    #+#             */
/*   Updated: 2024/07/02 20:15:34 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*first_b;

	if (*stack_b)
	{
		first_b = *stack_b;
		*stack_b = first_b->next;
		first_b->next = *stack_a;
		*stack_a = first_b;
		write(1, "pa\n", 3);
	}
}

void	push_b(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*first_a;

	if (*stack_a)
	{
		first_a = *stack_a;
		*stack_a = first_a->next;
		first_a->next = *stack_b;
		*stack_b = first_a;
		write(1, "pb\n", 3);
	}
}

