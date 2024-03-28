/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:44:17 by mjong             #+#    #+#             */
/*   Updated: 2024/03/28 17:36:08 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_node **stack_a, t_node **stack_b, t_push *push)
{
	count_stack_a(stack_a, push);
	printf("%d\n", push->size_a);
	count_stack_b(stack_b, push);
	printf("%d\n", push->size_b);

	while (!((*stack_a)->data < (*stack_a)->link->data && (*stack_a)->link->data))
	{
		if ((*stack_a)->data > (*stack_a)->link->data)
			ft_sa(stack_a);
		ft_ra(stack_a);
	}

	// if ((*stack_b)->data < (*stack_b)->link->data)
	// {
	// 	ft_rb(stack_b);
	// }
	// while (stack_b != 0)
	// 	ft_pa(stack_a, stack_b);
	
	ft_display(*stack_a);
	ft_display(*stack_b);

	free(*stack_a);
	free(*stack_b);

	// add_node_beg(&stack_a, 10);
	// stack_a = reverse(stack_a);
}
