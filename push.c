/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:30:52 by llai              #+#    #+#             */
/*   Updated: 2023/12/19 13:00:43 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_a(t_node *head_a, t_node *head_b, t_node *tail_b);
void	push_b(t_node *head_a, t_node *head_b, t_node *tail_a);

/* **************************************************************************
 * void	push_a(t_node *head_a, t_node *head_b)
 *
 * Summary of the function:
 * 
 * 	This function pushes the first element at the top of b
 * 	and put it at the top of a.
 * 	Do nothing if b is empty.
 * 	Display "pa".
 *
 * Parameters : The head node of the stacks.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	push_a(t_node *head_a, t_node *head_b, t_node *tail_b)
{
	t_node	*temp;

	temp = head_b->next;
	if (temp == tail_b)
		return ;
	remove_front(head_b);
	insert_front(temp->value, head_a);
	ft_printf("pa\n");
	free(temp);
}

/* **************************************************************************
 * void	push_b(t_node *head_a, t_node *head_b, t_node *tail_a);
 *
 * Summary of the function:
 * 
 * 	This function pushes the first element at the top of a
 * 	and put it at the top of b.
 * 	Do nothing if a is empty.
 * 	Display "pb".
 *
 * Parameters : The head node of the stacks.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	push_b(t_node *head_a, t_node *head_b, t_node *tail_a)
{
	t_node	*temp;

	temp = head_a->next;
	if (temp == tail_a)
		return ;
	remove_front(head_a);
	insert_front(temp->value, head_b);
	ft_printf("pb\n");
	free(temp);
}
