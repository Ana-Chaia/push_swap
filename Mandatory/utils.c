/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:42:51 by anacaro5          #+#    #+#             */
/*   Updated: 2024/07/02 18:52:53 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_swap *stackname)
{
	t_swap	*temp;

	temp = stackname;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	free_list(t_swap *stackhead)
{
	t_swap	*temp;

	temp = NULL;
	while (stackhead->next)
	{
		temp = stackhead->next;
		free(stackhead);
		stackhead = temp;
	}
	free(stackhead);
	stackhead = NULL;
	return (EXIT_SUCCESS);
}

int	get_max(t_swap *stackname)
{
	t_swap	*temp;
	int		max;

	temp = stackname;
	max = stackname->value;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

t_swap	*last_value(t_swap *stackname)
{
	if (stackname == NULL)
		return (0);
	while (stackname->next != NULL)
		stackname = stackname->next;
	return (stackname);
}

