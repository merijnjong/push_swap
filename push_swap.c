/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:14 by mjong             #+#    #+#             */
/*   Updated: 2024/04/23 15:59:38 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dup_check(int data)
{
	static int	prev[10000000];
	static int	index = 0;
	int			i;

	i = 0;
	while (i < index)
	{
		if (data == prev[i])
			return (0);
		i++;
	}
	prev[index++] = data;
	return (1);
}

int	ft_parse(int argc, char **argv)
{
	long	data;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		data = ft_atol(argv[i]);
		if (data > INT_MAX || data < INT_MIN)
			return (0);
		if (data == 0 && argv[i][0] != '0')
			return (0);
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9')
			|| (j == 0 && argv[i][j] == '-')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	init(t_push *push)
{
	push->size_a = 0;
	push->size_b = 0;
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_push	push;
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;
	long	data;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	init(&push);
	while (i < argc)
	{
		data = ft_atol(argv[i]);
		if (ft_parse(argc, argv) == 0 || ft_dup_check(data) == 0)
			ft_error();
		if (stack_a == NULL)
			stack_a = startstack(data);
		else
			add_node_end(&stack_a, data);
		i++;
	}
	ft_sort(&stack_a, &stack_b, &push, argc - 1);
	free(stack_a);
	return (0);
}
