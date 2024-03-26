/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:24:38 by mjong             #+#    #+#             */
/*   Updated: 2024/03/26 18:22:14 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_node	*add_node_beg(t_node *head, int data)
// {
// 	t_node	*ptr;

// 	ptr = malloc(sizeof(t_node));
// 	ptr->data = data;
// 	ptr->link = NULL;

// 	ptr->link = head;
// 	head = ptr;
// 	return (head);
// }

t_node	*startlist(int data)
{
	t_node	*head;

	head = malloc(sizeof(t_node));
	head->data = data;
	head->link = NULL;
	return (head);
}

void	add_node_beg(t_node **head, int data)
{
	t_node	*ptr;

	ptr = malloc(sizeof(t_node));
	ptr->data = data;
	ptr->link = NULL;

	ptr->link = *head;
	*head = ptr;
}

t_node	*add_node_end(t_node *ptr, int data)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	temp->data = data;
	temp->link = NULL;

	ptr->link = temp;
	return (temp);
}

void	ft_print_data(t_node *head)
{
	t_node	*ptr;

	ptr = NULL;
	if (head == NULL)
		ft_printf("Linked list is empty\n");
	ptr = head;
	while (ptr != NULL)
	{
		ft_printf("Data: %d\n", ptr->data);
		ptr = ptr->link;
	}
}

void	ft_node_count(t_node *head)
{
	int				count;
	t_node	*ptr;

	count = 0;
	ptr = NULL;
	if (head == NULL)
		ft_printf("Linked list is empty\n");
	ptr = head;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->link;
	}
	ft_printf("Number of nodes: %d\n", count);
}
