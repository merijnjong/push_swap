/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:31 by mjong             #+#    #+#             */
/*   Updated: 2024/04/23 18:03:55 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*link;
}	t_node;

typedef struct t_data
{
	int	size_a;
	int	size_b;
}	t_push;

void	ft_free_stacks(t_node **stack_a, t_node **stack_b);

// push_swap_utils.c

void	min_value(t_node **stack);
int		max_value(t_node *stack);
t_node	*startstack(int data);
void	add_node_end(t_node **head, int data);
void	ft_display(t_node *head);

// push_swap_utils2.c

void	ft_set_index(t_node **stack_a, int argc);
int		is_a_sorted(t_node **stack_a);
void	count_stack_a(t_node **stack, t_push *push);
void	ft_error(t_node **stack_a, t_node **stack_b);

// push_swap_operations.c

void	ft_sa(t_node **stack_a);
void	ft_sb(t_node **stack_b);
void	ft_ss(t_node **stack_a, t_node **stack_b);
void	ft_pa(t_node **stack_a, t_node **stack_b);
void	ft_pb(t_node **stack_a, t_node **stack_b);

// push_swap_operations2.c

void	ft_ra(t_node **head);
void	ft_rb(t_node **stack_b);
void	ft_rr(t_node **stack_a, t_node **stack_b);
void	ft_rra(t_node **head);
void	ft_rrb(t_node **stack_b);
// void	ft_rrr(t_node **stack_a, t_node **stack_b);

// push_swap_sort.c

void	ft_sort(t_node **stack_a, t_node **stack_b, t_push *push, int argc);
void	ft_sort_3(t_node **stack_a);

#endif
