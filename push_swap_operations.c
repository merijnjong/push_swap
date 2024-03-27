/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:08:32 by mjong             #+#    #+#             */
/*   Updated: 2024/03/27 17:04:59 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_sa(t_node *stack_a)
{
	int	temp;

	temp = 0;
	if (stack_a != NULL && stack_a->link != NULL)
	{
		temp = stack_a->data;
		stack_a->data = stack_a->link->data;
		stack_a->link->data = temp;	
	}
	return (stack_a);
}

t_node	*ft_sb(t_node *stack_b)
{
	int	temp;

	temp = 0;
	if (stack_b != NULL && stack_b->link != NULL)
	{
		temp = stack_b->data;
		stack_b->data = stack_b->link->data;
		stack_b->link->data = temp;	
	}
	return (stack_b);
}

void	ft_ss(t_node *stack_a, t_node *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void	ft_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*push;

	push = *stack_b;
	if (*stack_b != NULL)
	{
		*stack_b = (*stack_b)->link;
		push->link = *stack_a;
		*stack_a = push;
	}
}

void	ft_pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*push;

	push = *stack_a; // get the node to be pushed
	if (*stack_a != NULL)
	{
		*stack_a = (*stack_a)->link; // point to the next node
		push->link = *stack_b; // link the pushed node to the top of stack_b
		*stack_b = push; //update stack_b to point to the pushed node
	}
}

t_node	*reverse(t_node *head)
{
	t_node	*prev;
	t_node	*next;

	prev = NULL;
	next = NULL;
	while (head != NULL)
	{
		next = head->link;
		head->link = prev;
		prev = head;
		head = next;
	}
	head = prev;
	return (head);
}
