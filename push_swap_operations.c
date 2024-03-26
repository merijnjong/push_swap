/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:08:32 by mjong             #+#    #+#             */
/*   Updated: 2024/03/26 18:21:58 by mjong            ###   ########.fr       */
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
	t_node	*temp;
	t_node	*temp2;

	temp = *head;
	temp2 = (*head)->link;
	while (temp->link != NULL)
		temp = temp->link;
	if (*head != NULL && (*head)->link != NULL)
	{
		temp->link = *head;
		(*head)->link = NULL;
		*head = temp2;
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
