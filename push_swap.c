/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:14 by mjong             #+#    #+#             */
/*   Updated: 2024/03/20 16:36:28 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node	*add_node_end2(struct s_node *ptr, int data)
{
	struct s_node	*temp;

	temp = (struct s_node *)malloc(sizeof(struct s_node));
	temp->data = data;
	temp->link = NULL;
	ptr->link = temp;
	return (temp);
}

int	main(void)
{
	struct s_node	*head;
	struct s_node	*ptr;

	head = malloc(sizeof(struct s_node));
	head->data = 20;
	head->link = NULL;

	ptr = head;
	ptr = add_node_end2(ptr, 40);
	ptr = add_node_end2(ptr, 60);
	ptr = add_node_end2(ptr, 80);
	// ptr = head;
	// while (ptr != NULL)
	// {
	// 	ft_printf("%d\n", ptr->data);
	// 	ptr = ptr->link;
	// }
	ft_node_count(head);
	ft_print_data(head);
	return (0);
}
