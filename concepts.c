/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concept.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:51:10 by mjong             #+#    #+#             */
/*   Updated: 2024/04/04 16:52:56 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
