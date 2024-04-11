/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:24:38 by mjong             #+#    #+#             */
/*   Updated: 2024/04/11 15:32:43 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value(t_node *stack)
{
	int		max;
	t_node *ptr;

	max = 0;
	ptr = stack;
	while (ptr != NULL)
	{
		if (ptr->data > max)
			max = ptr->data;
		ptr = ptr->link;
	}
	return (max);
}

t_node	*startstack(int data)
{
	t_node	*head;

	head = malloc(sizeof(t_node));
	head->data = data;
	head->link = NULL;
	return (head);
}

void	count_stack_a(t_node **stack, t_push *push)
{
	t_node	*count;
	
	count = *stack;
	push->size_a = 0;
	while (count != 0)
	{
		count = count->link;
		push->size_a++;
	}
}

void	add_node_end(t_node **head, int data)
{
	t_node *new_node;
	t_node *current;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->data = data;
	new_node->link = NULL;
	current = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->link != NULL)
			current = current->link;
		current->link = new_node;
	}
}

void	ft_display(t_node *head)
{
	int		count;
	t_node	*ptr;

	count = 0;
	ptr = head;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->link;
	}
	ft_printf("\nNumber of nodes: %d\n", count);
	if (head == NULL)
		ft_printf("Linked list is empty\n");
	ptr = head;
	while (ptr != NULL)
	{
		ft_printf("Data: %d\n", ptr->data);
		ptr = ptr->link;
	}
}
