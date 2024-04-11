/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:44:17 by mjong             #+#    #+#             */
/*   Updated: 2024/04/11 14:42:20 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix(t_node **stack_a, t_node **stack_b, t_push *push)
{
	int		i;
	int		j;
	
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

void	ft_sort_2(t_node **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->link->data)
		ft_sa(stack_a);
}

void	ft_sort(t_node **stack_a, t_node **stack_b, t_push *push, int argc)
{
	if (is_a_sorted(stack_a) == 1 || argc == 1)
		return ;
	if (argc == 2)
		ft_sort_2(stack_a);
	if (argc == 3)
		ft_sort_3(stack_a);
	if (argc > 3)
		ft_radix(stack_a, stack_b, push);
	ft_display(*stack_a);
	ft_display(*stack_b);
	free(*stack_a);
}
