/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:08:32 by mjong             #+#    #+#             */
/*   Updated: 2024/03/27 14:35:43 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_sa(t_node *head)
{
	int	temp;

	temp = 0;
	if (head != NULL && head->link != NULL)
	{
		temp = head->data;
		head->data = head->link->data;
		head->link->data = temp;	
	}
	return (head);
}

void	ft_ra(t_node **head)
{
	t_node	*current;
	t_node	*new;

	current = *head; // point to the beginning of the current list
	new = (*head)->link; // point to the beginning of the new list
	if (*head != NULL && (*head)->link != NULL)
	{
		while (current->link != NULL)
		{
			current = current->link; // point to the last node of the current list
		}
		current->link = *head; // loop the list so that the last node points to the beginning of the current list
		(*head)->link = NULL; // make the beginning of the current list point to the end of the new list
		*head = new; // make the beginning of the new list point to the second place of the old list
	}
}

void	ft_rra(t_node **head)
{
	t_node	*temp;
	t_node	*temp2;

	temp = *head;
	temp2 = *head;
	if (*head != NULL && (*head)->link != NULL)
	{
		while (temp->link != NULL) // Traverse to find the last and second-to-last nodes
		{
			temp2 = temp; // second to last node
			temp = temp->link; // last node
		}
		temp2->link = NULL; // Make the second-to-last node the new last node
		temp->link = *head; // Connect the original last node to the head
		*head = temp; // Update the head to point to the new last node
	}
}

t_node	*reverse(t_node *head)
{
	t_node	*prev;
	t_node	*next;

	prev = NULL;
	next = NULL;
	while (head != NULL)
	{
		next = head->link;
		head->link = prev;
		prev = head;
		head = next;
	}
	head = prev;
	return (head);
}
