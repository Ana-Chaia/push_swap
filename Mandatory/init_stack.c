/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:42:30 by anacaro5          #+#    #+#             */
/*   Updated: 2024/07/11 12:36:42 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	final;
	int	intsign;

	final = 0;
	intsign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		intsign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		final = final * 10 + *str - '0';
		str++;
	}
	return (final * intsign);
}

t_swap	*new_node(int value)
{
	t_swap	*new;

	new = calloc(sizeof(t_swap), 1);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->posi = -1;
	new->target_posi = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	new->max_value = 0;
	new->min_value = 0;
	return (new);
}

t_swap	*init_stack(int ac, char **av)
{
	t_swap	*head;
	t_swap	*temp;
	int		i;

	i = 1;
	temp = new_node((ft_atoi(av[i])));
	head = temp;
	while (++i < ac)
	{
		temp->next = new_node((ft_atoi(av[i])));
		temp = temp->next;
	}
	init_index(head, av);
	return (head);
}

int	get_stack_size(t_swap *stack)
{
	int		size;
	t_swap	*temp;

	size = 0;
	temp = stack;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

t_info	*init_t_info(void)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->media = 0;
	info->stack_a = NULL;
	info->stack_b = NULL;

	return (info);
}
