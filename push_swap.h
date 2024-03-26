/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:31 by mjong             #+#    #+#             */
/*   Updated: 2024/03/26 18:22:47 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*link;
}	t_node;

// t_node	*add_node_beg(t_node *head, int data);
t_node	*startlist(int data);
void			add_node_beg(t_node **head, int data);
t_node	*add_node_end(t_node *ptr, int data);
t_node	*reverse(t_node *head);
void			ft_print_data(t_node *head);
void			ft_node_count(t_node *head);

t_node	*del_first(t_node *head);
t_node	*del_last(t_node *head);

t_node	*ft_sa(t_node *head);
void	ft_ra(t_node **head);

#endif


