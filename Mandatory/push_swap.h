/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:50:51 by anacaro5          #+#    #+#             */
/*   Updated: 2024/07/02 20:35:25 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

struct s_swap {
	int					value;
	int					index;
	int					posi;
	int					target_posi;
	int					cost_a;
	int					cost_b;
	int					max_index;
	int					max_value;
	int					min_value;
	struct s_swap		*next;
};
typedef struct s_swap	t_swap;

struct s_info{
	int		max_index;
	int		media;
	t_swap	*stack_a;
	t_swap	*stack_b;
};
typedef struct s_info	t_info;

// check_av.c
void	end_push_swap(void);
int		ft_isnum(char *str);
long	ft_atol(const char *str);
void	check_av(int ac, char **av);

// init_stack.c
int		ft_atoi(char *str);
t_swap	*new_node(int value);
t_swap	*init_stack(int ac, char **av);
int		get_stack_size(t_swap *stack);
t_info	*init_t_info(void);

// swap.c
void	swap_a(t_swap **stack_a);
void	swap_b(t_swap **stack_b);
void	swap_ab(t_info **stackname);

// rotate.c
void	rotate_a(t_swap **stack_a);
void	rotate_b(t_swap **stack_b);
void	rotate_ab(t_info *stackname);

//push.c
void	push_a(t_swap **stack_a, t_swap **stack_b);
void	push_b(t_swap **stack_a, t_swap **stack_b);

// reverse_rotate.c
void	reverserotate(t_swap **stackname);
void	reverserotate_a(t_swap **stack_a);
void	reverserotate_b(t_swap **stack_b);
void	reverserotate_ab(t_info *stackname);

// utils.c
int		already_sorted(t_swap *stackname);
int		free_list(t_swap *stackhead);
int		get_max(t_swap *stackname);
t_swap	*last_value(t_swap *stackname);



// main.c
int	free_all(t_info *stackname);




// init_infos.c
void	find_order(char **av);
void	init_index(t_swap *stack_a, char **av);
void	init_stack_posi(t_swap *stackname);
void	init_target_posi(t_info *stackname);

// work_moves.c
// void		all_to_b(t_swap **stack_a, t_swap **stack_b);
void		all_to_b(t_info *info);

void	moving_to_a(t_info *info, t_swap *cheap_node);
void	work_a(t_info *info, int index);
void	work_b(t_info *info, int index);
void	work_both(t_info *info);

// push_swap.c
int		sort_two(t_swap *stackname);
void	sort_three(t_info *stackname);
void	sort_a(t_swap **stackname);
void	sort_many(t_info *stackname);
void	push_swap(t_info *info, char **av);

// check_costs.c
void	init_costs(t_info *stackname);
void	cost_a_n_b(t_swap *stack_a, t_swap *stack_b, char stack_id, int posi);
int		total_moves_each(t_swap *stackname);
t_swap	*find_smallest_move(t_swap *stackname);


void print_list(t_swap *head);


#endif