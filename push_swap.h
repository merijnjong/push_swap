/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:31 by mjong             #+#    #+#             */
/*   Updated: 2024/03/26 18:18:20 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

struct s_node
{
	int				data;
	struct s_node	*link;
}	t_node;

// struct s_node	*add_node_beg(struct s_node *head, int data);
struct s_node	*startlist(int data);
void			add_node_beg(struct s_node **head, int data);
struct s_node	*add_node_end(struct s_node *ptr, int data);
struct s_node	*reverse(struct s_node *head);
void			ft_print_data(struct s_node *head);
void			ft_node_count(struct s_node *head);

struct s_node	*del_first(struct s_node *head);
struct s_node	*del_last(struct s_node *head);

struct s_node	*ft_sa(struct s_node *head);
void	ft_ra(struct s_node **head);

#endif


