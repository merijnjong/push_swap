/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:44:17 by mjong             #+#    #+#             */
/*   Updated: 2024/04/17 15:34:55 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix(t_node **stack_a, t_node **stack_b, t_push *push)
{
	int	i;
	int	j;

	j = 0;
	while (is_a_sorted(stack_a) == 0)
	{
		i = 0;
		count_stack_a(stack_a, push);
		while (i < push->size_a)
		{
			if (((*stack_a)->data >> j) & 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
			i++;
		}
		while (*stack_b != NULL)
			ft_pa(stack_a, stack_b);
		j++;
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

void	ft_sort_3(t_node **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->link->data
		&& (*stack_a)->data > (*stack_a)->link->link->data)
		ft_ra(stack_a);
	if ((*stack_a)->link->data > (*stack_a)->data
		&& (*stack_a)->link->data > (*stack_a)->link->link->data)
		ft_rra(stack_a);
	if ((*stack_a)->data > (*stack_a)->link->data)
		ft_sa(stack_a);
}

t_node	*append_stack(t_node *neg_stack, t_node *pos_stack)
{
	t_node	*result_stack;

	result_stack = NULL;
	if (pos_stack == NULL)
		return (neg_stack);
	result_stack = pos_stack;
	while (result_stack->link != NULL)
		result_stack = result_stack->link;
	result_stack->link = neg_stack;
	return (pos_stack);
}

t_node	*pos_to_neg(t_node *stack)
{
	t_node	*neg_stack;
	int		data;

	neg_stack = NULL;
	while (stack != NULL)
	{
		data = stack->data;
		if (data > 0)
			data *= -1;
		add_node_end(&neg_stack, data);
		stack = stack->link;
	}
	return (neg_stack);
}

t_node	*neg_to_pos(t_node *stack)
{
	t_node	*pos_stack;

	pos_stack = NULL;
	while (stack != NULL)
	{
		add_node_end(&pos_stack, -(stack->data));
		stack = stack->link;
	}
	return (pos_stack);
}

void	ft_sort(t_node **stack_a, t_node **stack_b, t_push *push, int argc)
{
	t_node	*ptr;
	t_node	*neg_stack;
	t_node	*pos_stack;

	ptr = *stack_a;
	neg_stack = NULL;
	pos_stack = NULL;
	if (is_a_sorted(stack_a) == 1 || argc == 1)
		return ;
	if (argc == 2)
	{
		if ((*stack_a)->data > (*stack_a)->link->data)
			ft_sa(stack_a);
	}
	if (argc == 3)
		ft_sort_3(stack_a);
	if (argc > 3)
	{
		while (ptr != NULL)
		{
			if (ptr->data < 0)
				add_node_end(&neg_stack, ptr->data);
			else
				add_node_end(&pos_stack, ptr->data);
			ptr = ptr->link;
		}
		ft_radix(&pos_stack, stack_b, push);
		neg_stack = neg_to_pos(neg_stack);
		ft_radix(&neg_stack, stack_b, push);
		neg_stack = reverse(neg_stack);
		neg_stack = pos_to_neg(neg_stack);
		*stack_a = append_stack(pos_stack, neg_stack);
	}
    // ft_display(*stack_a);
}
