/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:48:29 by mjong             #+#    #+#             */
/*   Updated: 2024/04/23 17:58:17 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_node **stack_a)
{
	t_node	*current;
	t_node	*new;

	current = *stack_a;
	new = (*stack_a)->link;
	if (*stack_a != NULL && (*stack_a)->link != NULL)
	{
		while (current->link != NULL)
		{
			current = current->link;
		}
		current->link = *stack_a;
		(*stack_a)->link = NULL;
		*stack_a = new;
	}
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void	ft_rr(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	t_node	*new;

	current = *stack_a;
	new = (*stack_a)->link;
	if (*stack_a != NULL && (*stack_a)->link != NULL)
	{
		while (current->link != NULL)
			current = current->link;
		current->link = *stack_a;
		(*stack_a)->link = NULL;
		*stack_a = new;
	}
	current = *stack_b;
	new = (*stack_b)->link;
	if (*stack_b != NULL && (*stack_b)->link != NULL)
	{
		while (current->link != NULL)
			current = current->link;
		current->link = *stack_b;
		(*stack_b)->link = NULL;
		*stack_b = new;
	}
	write(1, "rr\n", 3);
}

void	ft_rra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*temp2;

	temp = *stack_a;
	temp2 = *stack_a;
	if (*stack_a != NULL && (*stack_a)->link != NULL)
	{
		while (temp->link != NULL)
		{
			temp2 = temp;
			temp = temp->link;
		}
		temp2->link = NULL;
		temp->link = *stack_a;
		*stack_a = temp;
	}
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

// void	ft_rrr(t_node **stack_a, t_node **stack_b)
// {
// 	t_node	*temp;
// 	t_node	*temp2;

// 	temp = *stack_a;
// 	temp2 = *stack_a;
// 	if (*stack_a != NULL && (*stack_a)->link != NULL)
// 	{
// 		while (temp->link != NULL)
// 		{
// 			temp2 = temp;
// 			temp = temp->link;
// 		}
// 		temp2->link = NULL;
// 		temp->link = *stack_a;
// 		*stack_a = temp;
// 	}
// 	temp = *stack_b;
// 	temp2 = *stack_b;
// 	if (*stack_b != NULL && (*stack_b)->link != NULL)
// 	{
// 		while (temp->link != NULL)
// 		{
// 			temp2 = temp;
// 			temp = temp->link;
// 		}
// 		temp2->link = NULL;
// 		temp->link = *stack_b;
// 		*stack_b = temp;
// 	}
// 	write(1, "rrr\n", 4);
// }
