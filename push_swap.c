/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:14 by mjong             #+#    #+#             */
/*   Updated: 2024/04/11 17:55:30 by mjong            ###   ########.fr       */
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
	int	data;
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		data = ft_atoi(argv[i]);
		if ((data == 0 && argv[i][0] != '0')
		|| (data > 2147483647 && data < -2147483648))
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
	if (argc == 2 && !argv[1][0])
		return (1);
	while (i < argc)
	{
		data = ft_atoi(argv[i]);
		if (ft_parse(argc, argv) == 0 || ft_dup_check(data) == 0)
			return (write(1, "Error\n", 6));
		if (stack_a == NULL)
			stack_a = startstack(data);
		else
			add_node_end(&stack_a, data);
		i++;
	}
	ft_sort(&stack_a, &stack_b, &push, argc - 1);
	return (0);
}
