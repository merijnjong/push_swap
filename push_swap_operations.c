/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:08:32 by mjong             #+#    #+#             */
/*   Updated: 2024/03/28 12:58:33 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_node **stack_a)
{
	t_node	*temp;

	if (stack_a != NULL && (*stack_a)->link != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->link;
		temp->link = (*stack_a)->link;
		(*stack_a)->link = temp;	
	}
	write(1, "sa\n", 3);
}

void	ft_sb(t_node **stack_b)
{
	t_node	*temp;

	if (stack_b != NULL && (*stack_b)->link != NULL)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->link;
		temp->link = (*stack_b)->link;
		(*stack_b)->link = temp;	
	}
	write(1, "sa\n", 3);
}

void	ft_ss(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (stack_a != NULL && (*stack_a)->link != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->link;
		temp->link = (*stack_a)->link;
		(*stack_a)->link = temp;	
	}
	temp = NULL;
	if (stack_b != NULL && (*stack_b)->link != NULL)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->link;
		temp->link = (*stack_b)->link;
		(*stack_b)->link = temp;	
	}
	write(1, "ss\n", 3);
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
	write(1, "pa\n", 3);
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
	write(1, "pb\n", 3);
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
