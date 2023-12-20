/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:12:37 by llai              #+#    #+#             */
/*   Updated: 2023/12/20 09:49:57 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_a(t_node *head_a, t_node *tail_a, bool is_print);
void	rotate_b(t_node *head_b, t_node *tail_b, bool is_print);

/* **************************************************************************
 * void	rotate_a(t_node *head_a, t_node *tail_a, bool is_print);
 *
 * Summary of the function:
 * 
 * 	This function shifts up all elements of stack a by 1.
 * 	The first element becomes the last one.
 * 	Display "ra";
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	rotate_a(t_node *head_a, t_node *tail_a, bool is_print)
{
	t_node	*temp;

	if (head_a->next == tail_a)
		return ;
	temp = head_a->next;
	remove_front(head_a);
	insert_end(temp->value, tail_a);
	if (is_print)
		ft_printf("ra\n");
	free(temp);
}

/* **************************************************************************
 * void	rotate_b(t_node *head_b, t_node *tail_b, bool is_print);
 *
 * Summary of the function:
 * 
 * 	This function shifts up all elements of stack b by 1.
 * 	The first element becomes the last one.
 * 	Display "rb";
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	rotate_b(t_node *head_b, t_node *tail_b, bool is_print)
{
	t_node	*temp;

	if (head_b->next == tail_b)
		return ;
	temp = head_b->next;
	remove_front(head_b);
	insert_end(temp->value, tail_b);
	if (is_print)
		ft_printf("rb\n");
	free(temp);
}

/* **************************************************************************
 * void	rotate_both(t_node *head_a, t_node *tail_a,
 * 					t_node *head_b, t_node *tail_b);
 *
 * Summary of the function:
 * 
 * 	This function shifts up all elements of stack a & b by 1.
 * 	The first element becomes the last one.
 * 	Display "rr";
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	rotate_both(t_node *head_a, t_node *tail_a,
			t_node *head_b, t_node *tail_b)
{
	rotate_a(head_a, tail_a, false);
	rotate_b(head_b, tail_b, false);
	ft_printf("rr\n");
}
