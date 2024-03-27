/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:14 by mjong             #+#    #+#             */
/*   Updated: 2024/03/27 18:20:19 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*ptr;
	int		i;
	int		data;

	stack_a = NULL;
	stack_b = NULL;
	ptr = NULL;
	i = 1;
	while (i < argc)
	{
		data = ft_atoi(argv[i]);
		if (stack_a == NULL)
		{
			stack_a = startstack(data);
			ptr = stack_a;
		}
		else
			ptr = add_node_end(ptr, data);
		i++;
	}
	// add_node_beg(&stack_a, 10);
	// stack_a = reverse(stack_a);
	
	ft_display(stack_a);
	ft_display(stack_b);

	ft_printf("\noperation\n\n");

	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);

	ft_display(stack_a);
	ft_display(stack_b);
	
	ft_printf("\noperation\n\n");
	
	ft_ss(stack_a, stack_b);

	ft_display(stack_a);
	ft_display(stack_b);

	ft_printf("\noperation\n\n");
	
	ft_rr(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);

	ft_display(stack_a);
	ft_display(stack_b);
	
	return (0);
}
