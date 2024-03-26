/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:24:38 by mjong             #+#    #+#             */
/*   Updated: 2024/03/26 15:47:27 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// struct s_node	*add_node_beg(struct s_node *head, int data)
// {
// 	struct s_node	*ptr;

// 	ptr = malloc(sizeof(struct s_node));
// 	ptr->data = data;
// 	ptr->link = NULL;

// 	ptr->link = head;
// 	head = ptr;
// 	return (head);
// }

struct s_node	*startlist(int data)
{
	struct s_node	*head;

	head = malloc(sizeof(struct s_node));
	head->data = data;
	head->link = NULL;
	return (head);
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

void	add_node_beg(struct s_node **head, int data)
{
	struct s_node	*ptr;

	ptr = malloc(sizeof(struct s_node));
	ptr->data = data;
	ptr->link = NULL;

	ptr->link = *head;
	*head = ptr;
}

struct s_node	*add_node_end(struct s_node *ptr, int data)
{
	struct s_node	*temp;

	temp = (struct s_node *)malloc(sizeof(struct s_node));
	temp->data = data;
	temp->link = NULL;

	ptr->link = temp;
	return (temp);
}

void	ft_print_data(struct s_node *head)
{
	struct s_node	*ptr;

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

void	ft_node_count(struct s_node *head)
{
	int				count;
	struct s_node	*ptr;

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
