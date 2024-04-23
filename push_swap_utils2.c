/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:58:57 by mjong             #+#    #+#             */
/*   Updated: 2024/04/23 18:03:41 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index(t_node **stack_a, int argc)
{
	t_node	*temp;
	t_node	*node_to_change;
	int		index;
	int		highest;

	index = argc;
	while (index != 0)
	{
		node_to_change = NULL;
		temp = *stack_a;
		highest = INT_MIN;
		while (temp)
		{
			if (temp->data > highest && temp->index == 0)
			{
				highest = temp->data;
				node_to_change = temp;
			}
			temp = temp->link;
		}
		if (node_to_change)
			node_to_change->index = index;
		index--;
	}
}

int	is_a_sorted(t_node **stack_a)
{
	t_node	*ptr;

	ptr = *stack_a;
	while (ptr != NULL && ptr->link != NULL)
	{
		if (ptr->data < ptr->link->data)
			ptr = ptr->link;
		else
			return (0);
	}
	return (1);
}

void	count_stack_a(t_node **stack, t_push *push)
{
	t_node	*count;

	count = *stack;
	push->size_a = 0;
	while (count != 0)
	{
		count = count->link;
		push->size_a++;
	}
}

void	ft_error(t_node **stack_a, t_node **stack_b)
{
	write(2, "Error\n", 6);
	ft_free_stacks(stack_a, stack_b);
	exit(EXIT_FAILURE);
}
