/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:31 by mjong             #+#    #+#             */
/*   Updated: 2024/03/27 17:05:04 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*link;
}	t_node;

// t_node	*add_node_beg(t_node *head, int data);

// push_swap_utils.c

t_node	*startstack(int data);
void	add_node_beg(t_node **head, int data);
t_node	*add_node_end(t_node *ptr, int data);
void	ft_display(t_node *head);

// push_swap_delete.c

t_node	*del_first(t_node *head);
t_node	*del_last(t_node *head);

// push_swap_operations.c

t_node	*ft_sa(t_node *stack_a);
t_node	*ft_sb(t_node *stack_b);
void	ft_ss(t_node *stack_a, t_node *stack_b);
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

#endif


