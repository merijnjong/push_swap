/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:44:17 by mjong             #+#    #+#             */
/*   Updated: 2024/04/04 16:53:54 by mjong            ###   ########.fr       */
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
	printf("number moves: %d\n", moves);
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

void	ft_sort_2(t_node **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->link->data)
		ft_sa(stack_a);
}

void	ft_sort(t_node **stack_a, t_node **stack_b, t_push *push, int argc)
{
	int smlst_num = 0;
	count_stack_a(stack_a, push);
	printf("%d\n", push->size_a);
	count_stack_b(stack_b, push);
	printf("%d\n", push->size_b);

	if (argc == 1)
		return ;
	if (argc == 2)
		ft_sort_2(stack_a);
	if (argc == 3)
		ft_sort_3(stack_a);
	if (argc > 3)
	{
		smlst_num = ft_find_num(stack_a, stack_b);
		ft_sort_4(stack_a, stack_b);
	}
	while ((*stack_a)->data != smlst_num)
		ft_ra(stack_a);
	ft_display(*stack_a);
	ft_display(*stack_b);
	free(*stack_a);
}
