/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:48:29 by mjong             #+#    #+#             */
/*   Updated: 2024/03/27 17:03:15 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_node **stack_a)
{
	t_node	*current;
	t_node	*new;

	current = *stack_a; // point to the beginning of the current list
	new = (*stack_a)->link; // point to the beginning of the new list
	if (*stack_a != NULL && (*stack_a)->link != NULL)
	{
		while (current->link != NULL)
		{
			current = current->link; // point to the last node of the current list
		}
		current->link = *stack_a; // loop the list so that the last node points to the beginning of the current list
		(*stack_a)->link = NULL; // make the beginning of the current list point to the end of the new list
		*stack_a = new; // make the beginning of the new list point to the second place of the old list
	}
}

void	ft_rb(t_node **stack_b)
{
	t_node	*current;
	t_node	*new;

	current = *stack_b;
	new = (*stack_b)->link;
	if (*stack_b != NULL && (*stack_b)->link != NULL)
	{
		while (current->link != NULL)
		{
			current = current->link;
		}
		current->link = *stack_b;
		(*stack_b)->link = NULL;
		*stack_b = new;
	}
}

void	ft_rr(t_node **stack_a, t_node **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

void	ft_rra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*temp2;

	temp = *stack_a;
	temp2 = *stack_a;
	if (*stack_a != NULL && (*stack_a)->link != NULL)
	{
		while (temp->link != NULL) // Traverse to find the last and second-to-last nodes
		{
			temp2 = temp; // second to last node
			temp = temp->link; // last node
		}
		temp2->link = NULL; // Make the second-to-last node the new last node
		temp->link = *stack_a; // Connect the original last node to stack_a
		*stack_a = temp; // Update stack_a to point to the new last node
	}
}

void	ft_rrb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*temp2;

	temp = *stack_b;
	temp2 = *stack_b;
	if (*stack_b != NULL && (*stack_b)->link != NULL)
	{
		while (temp->link != NULL)
		{
			temp2 = temp;
			temp = temp->link;
		}
		temp2->link = NULL;
		temp->link = *stack_b;
		*stack_b = temp;
	}
}

void	ft_rrr(t_node **stack_a, t_node **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}
