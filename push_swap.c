/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:14 by mjong             #+#    #+#             */
/*   Updated: 2024/04/04 18:08:19 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parse(int data)
{
	static int	prev[500];
	static int	index = 0;
	int			i;

	i = 0;
	while (i < index)
	{
		if (data == prev[i])
		{
			fprintf(stderr, "Wrong data\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	prev[index++] = data;
	return (0);
}

void	init(t_push *push)
{
	push->size_a = 0;
	push->size_b = 0;
}

int	main(int argc, char *argv[])
{
	t_push	push;
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;
	int		data;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	init(&push);
	while (i < argc)
	{
		data = ft_atoi(argv[i]);
		ft_parse(data);
		if (stack_a == NULL)
			stack_a = startstack(data);
		else
			add_node_end(&stack_a, data);
		i++;
	}
	ft_sort(&stack_a, &stack_b, &push, argc - 1);
	return (0);
}
