/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:44:35 by mjong             #+#    #+#             */
/*   Updated: 2024/03/26 18:22:22 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*del_first(t_node *head)
{
	t_node	*temp;
	
	if (head == NULL)
		ft_printf("List is already empty");
	else
	{
		temp = head;
		head = head->link;
		free(temp);
	}
	return (head);
}

t_node	*del_last(t_node *head)
{
	t_node	*temp;
	t_node	*temp2;
	
	if (head == NULL)
		ft_printf("List is already empty");
	else if (head->link == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		temp = head;
		temp2 = head;
		while (temp->link != NULL)
		{
			temp2 = temp;
			temp = temp->link;
		}
		temp2->link = NULL;
		free(temp);
		temp = NULL;
	}
	return (head);
}
