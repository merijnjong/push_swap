/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:14 by mjong             #+#    #+#             */
/*   Updated: 2024/03/26 15:53:06 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	struct s_node	*head;
	struct s_node	*ptr;
	int				i;
	int				data;

	head = NULL;
	ptr = NULL;
	i = 1;
	while (i < argc)
	{
		data = ft_atoi(argv[i]);
		if (head == NULL)
		{
			head = startlist(data);
			ptr = head;
		}
		else
			ptr = add_node_end(ptr, data);
		i++;
	}
	// add_node_beg(&head, 10);
	// head = reverse(head);
	ft_node_count(head);
	ft_print_data(head);
	return (0);
}
