/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:49:58 by llai              #+#    #+#             */
/*   Updated: 2023/12/20 09:50:32 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_rev_a(t_node *head_a, t_node *tail_a, bool is_print);
void	rotate_rev_b(t_node *head_b, t_node *tail_b, bool is_print);

/* **************************************************************************
 * void	rotate_rev_a(t_node *head_a, t_node *tail_a, bool is_print)
 *
 * Summary of the function:
 * 
 * 	This function shifts down all elements of stack a by 1.
 * 	The last element becomes the first one.
 * 	Display "rra";
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	rotate_rev_a(t_node *head_a, t_node *tail_a, bool is_print)
{
	t_node	*temp;

	if (tail_a->prev == head_a)
		return ;
	temp = tail_a->prev;
	remove_end(tail_a);
	insert_front(temp->value, head_a);
	if (is_print)
		ft_printf("rra\n");
	free(temp);
}

/* **************************************************************************
 * void	rotate_rev_b(t_node *head_b, t_node *tail_b, bool is_print)
 *
 * Summary of the function:
 * 
 * 	This function shifts down all elements of stack b by 1.
 * 	The last element becomes the first one.
 * 	Display "rrb";
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	rotate_rev_b(t_node *head_b, t_node *tail_b, bool is_print)
{
	t_node	*temp;

	if (tail_b->prev == head_b)
		return ;
	temp = tail_b->prev;
	remove_end(tail_b);
	insert_front(temp->value, head_b);
	if (is_print)
		ft_printf("rrb\n");
	free(temp);
}

/* **************************************************************************
 * void	rotate_rev_both(t_node *head_a, t_node *tail_a,
 * 						t_node *head_b, t_node *tail_b);
 *
 * Summary of the function:
 * 
 * 	This function shifts down all elements of stack a & b by 1.
 * 	The last element becomes the first one.
 * 	Display "rrr";
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	rotate_rev_both(t_node *head_a, t_node *tail_a,
			t_node *head_b, t_node *tail_b)
{
	rotate_rev_a(head_a, tail_a, false);
	rotate_rev_b(head_b, tail_b, false);
	ft_printf("rrr\n");
}
