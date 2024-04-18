/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concepts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:51:10 by mjong             #+#    #+#             */
/*   Updated: 2024/04/18 12:42:13 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*append_stack(t_node *pos_stack, t_node *neg_stack)
{
	t_node	*result_stack;

	result_stack = NULL;
	if (neg_stack == NULL)
		return (pos_stack);
	result_stack = neg_stack;
	while (result_stack->link != NULL)
		result_stack = result_stack->link;
	result_stack->link = pos_stack;
	return (neg_stack);
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

void	ft_sort_4(t_node **stack_a, t_node **stack_b)
{
	int moves = 0;
	while (moves != 65000)
	{
		if (*stack_a == NULL)
		{
			while ((*stack_b) != NULL)
			{
				ft_pa(stack_a, stack_b);
				moves++;
			}	
			break ;
		}
		if ((*stack_a)->data < (*stack_b)->data && (*stack_a)->data > (*stack_b)->link->data)
		{
			ft_pb(stack_a, stack_b);
			moves++;
			ft_sb(stack_b);
			moves++;
		}
		else
		{
			ft_rb(stack_b);
			moves++;
		}
	}
	printf("Number of moves: %d\n", moves);
}

int	ft_find_num(t_node **stack_a, t_node **stack_b)
{
	t_node *smlst_num = *stack_a;
	t_node *bgst_num = *stack_a;
	t_node *current = (*stack_a)->link;

	while (current != NULL)
	{
		if (current->data < smlst_num->data)
			smlst_num = current;
		if (current->data > bgst_num->data)
			bgst_num = current;
		current = current->link;
	}
	while (*stack_a != smlst_num)
	{
		if ((*stack_a)->link == smlst_num)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
	ft_pb(stack_a, stack_b);
	while (*stack_a != bgst_num)
	{
		if ((*stack_a)->link == bgst_num)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
	ft_pb(stack_a, stack_b);
	return (smlst_num->data);
}

void	ft_sort_4(t_node **stack_a, t_node **stack_b)
{
	int moves = 0;
	while (*stack_a != NULL)
	{
		t_node *smlst_num;
		t_node *current;

		smlst_num = *stack_a;
		current = (*stack_a)->link;
		while (current != NULL)
		{
			if (current->data < smlst_num->data)
				smlst_num = current;
			current = current->link;
		}
		while (*stack_a != smlst_num)
		{
			if ((*stack_a)->link == smlst_num)
			{
				ft_ra(stack_a);
				moves++;
			}
			else
			{
				ft_rra(stack_a);
				moves++;
			}
		}
		ft_pb(stack_a, stack_b);
		moves++;
	}
	while (*stack_b != NULL)
	{
		ft_pa(stack_a, stack_b);
		moves++;
	}
	printf("Number of moves: %d\n", moves);
}
