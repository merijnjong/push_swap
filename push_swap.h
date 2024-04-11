/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:31 by mjong             #+#    #+#             */
/*   Updated: 2024/04/11 14:05:50 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# ifndef LONG_MAX
#  define LONG_MAX 2147483647
# endif

typedef struct s_node
{
	int				data;
	struct s_node	*link;
}	t_node;

typedef struct t_data
{
	int	size_a;
	int	size_b;
}	t_push;

// push_swap_utils.c

t_node	*startstack(int data);
void	count_stack_a(t_node **stack, t_push *push);
void	count_stack_b(t_node **stack, t_push *push);
void	add_node_beg(t_node **head, int data);
void	add_node_end(t_node **head, int data);
void	ft_display(t_node *head);

// push_swap_delete.c

t_node	*del_first(t_node *head);
t_node	*del_last(t_node *head);

// push_swap_operations.c

void	ft_sa(t_node **stack_a);
void	ft_sb(t_node **stack_b);
void	ft_ss(t_node **stack_a, t_node **stack_b);
void	ft_pa(t_node **stack_a, t_node **stack_b);
void	ft_pb(t_node **stack_a, t_node **stack_b);
t_node	*reverse(t_node *head);

// push_swap_operations2.c

void	ft_ra(t_node **head);
void	ft_rb(t_node **stack_b);
void	ft_rr(t_node **stack_a, t_node **stack_b);
void	ft_rra(t_node **head);
void	ft_rrb(t_node **stack_b);
void	ft_rrr(t_node **stack_a, t_node **stack_b);

// push_swap_sort.c

void	ft_sort(t_node **stack_a, t_node **stack_b, t_push *push, int argc);
void	ft_sort_2(t_node **stack_a);
void	ft_sort_3(t_node **stack_a);
// void	ft_target_node(t_node *stack_a, t_node *stack_b);
int		is_a_sorted(t_node **stack_a);
void	ft_radix(t_node **stack_a, t_node **stack_b, t_push *push);

#endif


