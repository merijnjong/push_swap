/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:14 by mjong             #+#    #+#             */
/*   Updated: 2024/03/26 18:03:20 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	struct s_node	*stack_a;
	struct s_node	*ptr;
	int				i;
	int				data;

	stack_a = NULL;
	ptr = NULL;
	i = 1;
	while (i < argc)
	{
		data = ft_atoi(argv[i]);
		if (stack_a == NULL)
		{
			stack_a = startlist(data);
			ptr = stack_a;
		}
		else
			ptr = add_node_end(ptr, data);
		i++;
	}
	// add_node_beg(&stack_a, 10);
	// stack_a = reverse(stack_a);
	ft_ra(&stack_a);
	ft_sa(stack_a);
	ft_node_count(stack_a);
	ft_print_data(stack_a);
	return (0);
}
