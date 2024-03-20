/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:24:38 by mjong             #+#    #+#             */
/*   Updated: 2024/03/20 16:36:07 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node *add_node_end2(struct s_node *ptr, int data)
{
	struct s_node	*temp;

	temp = (struct s_node *)malloc(sizeof(struct s_node));
	temp->data = data;
	temp->link = NULL;
	ptr->link = temp;
	return (temp);
}

void	add_node_end(struct s_node *head, int data)
{
	struct s_node	*ptr;
	struct s_node	*temp;

	ptr = head;
	temp = (struct s_node *)malloc(sizeof(struct s_node));
	temp->data = data;
	temp->link = NULL;
	while (ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	ptr->link = temp;
}

void	ft_print_data(struct s_node *head)
{
	struct s_node	*ptr;

	ptr = NULL;
	if (head == NULL)
		ft_printf("Linked list is empty");
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
		ft_printf("Linked list is empty");
	ptr = head;
	while (ptr != NULL)
	{	
		count++;
		ptr = ptr->link;
	}
	ft_printf("Number of nodes: %d\n", count);
}

// int	main(void)
// {
// 	struct s_node	*head;
// 	struct s_node	*current;

// 	head = malloc(sizeof(struct s_node));
// 	head->data = 20;
// 	head->link = NULL;

// 	current = malloc(sizeof(struct s_node));
// 	current->data = 40;
// 	current->link = NULL;
// 	head->link = current;

// 	current = malloc(sizeof(struct s_node));
// 	current->data = 60;
// 	current->link = NULL;
// 	head->link->link = current;

// 	add_node_end(head, 80);
// 	ft_node_count(head);
// 	ft_print_data(head);
// 	return (0);
// }