/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:08:32 by mjong             #+#    #+#             */
/*   Updated: 2024/03/26 18:20:19 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node	*ft_sa(struct s_node *head)
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

void	ft_ra(struct s_node **head)
{
	struct s_node	*temp;
	struct s_node	*temp2;

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

struct s_node	*reverse(struct s_node *head)
{
	struct s_node	*prev;
	struct s_node	*next;

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
