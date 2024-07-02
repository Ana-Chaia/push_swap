/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:53:19 by anacaro5          #+#    #+#             */
/*   Updated: 2024/07/02 20:34:37 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_swap *head)
{
	t_swap *temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}

int	free_all(t_info *stackname) 
{
	free_list((stackname)->stack_a);
	free(stackname);
	return (EXIT_SUCCESS);
}


int	main(int ac, char **av)
{
	t_info	*info;
	int		stack_size;

	check_av(ac, av);
	info = init_t_info();
	info->stack_a = init_stack(ac, av);
	stack_size = get_stack_size(info->stack_a);
	if (already_sorted(info->stack_a))
		return (free_all(info));
	if (stack_size == 2)
	{
		sort_two(info->stack_a);
		return (free_all(info));
	}
	if (stack_size == 3)
	{
		sort_three(info);
		return (free_all(info));
	}
	else
		push_swap(info, &av[1]);
	free_all(info);

	
	
	
	
	//print_list(info->stack_a);

	
	
	
	
	//printf("%d, stack_size\n", stack_size);

//descobrir como colocar o index de cada número na stack
	
	return (0);
}



//MUDAR CALLOC!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!