/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:45:53 by llai              #+#    #+#             */
/*   Updated: 2023/12/19 13:02:30 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_a(t_node *head);
void	swap_b(t_node *head);
void	swap_both(t_node *head_a, t_node *head_b);

/* **************************************************************************
 * void	swap_a(t_node *head)
 *
 * Summary of the function:
 * 
 * 	This function swaps the first 2 elements at the top of stack a.
 * 	Do nothing if there is only one or no elements.
 * 	It also prints out 'sa'.
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	swap_a(t_node *head)
{
	t_node	*temp;

	temp = head->next;
	head->next->next->prev = head;
	head->next = head->next->next;
	temp->next = head->next->next;
	temp->prev = head->next;
	head->next->next->prev = temp;
	head->next->next = temp;
	ft_printf("sa\n");
}

/* **************************************************************************
 * void	swap_b(t_node *head)
 *
 * Summary of the function:
 * 
 * 	This function swaps the first 2 elements at the top of stack b.
 * 	Do nothing if there is only one or no elements.
 * 	It also prints out 'sb'.
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	swap_b(t_node *head)
{
	t_node	*temp;

	temp = head->next;
	head->next->next->prev = head;
	head->next = head->next->next;
	temp->next = head->next->next;
	temp->prev = head->next;
	head->next->next->prev = temp;
	head->next->next = temp;
	ft_printf("sb\n");
}

/* **************************************************************************
 * void	swap_both(t_node *head_a, t_node *head_b)
 *
 * Summary of the function:
 * 
 * 	This function swaps the first 2 elements at the top of stack a & b.
 * 	Do nothing if there is only one or no elements.
 * 	It also prints out 'ss'.
 *
 * Parameters : The head node of the stacks.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	swap_both(t_node *head_a, t_node *head_b)
{
	swap_a(head_a);
	swap_b(head_b);
}
