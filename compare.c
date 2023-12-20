/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:12:58 by llai              #+#    #+#             */
/*   Updated: 2023/12/20 20:56:22 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	is_sorted(t_node *head, t_node *tail);
bool	cmp(t_node *node_1, t_node *node_2);
bool	is_smallest(t_node *head, t_node *tail, t_node *node);
bool	is_largest(t_node *head, t_node *tail, t_node *node);

/* **************************************************************************
 * bool	is_sorted(t_node *head, t_node *tail)
 *
 * Summary of the function:
 * 
 * 	This function checks if the nodes in the list are sorted
 * 	from small to large.
 *
 * Parameters : The head node and the tail node.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	is_sorted(t_node *head, t_node *tail)
{
	t_node	*curr;

	curr = head->next;
	while (curr != tail->prev)
	{
		if (curr->value > curr->next->value)
			return (false);
		curr = curr->next;
	}
	return (true);
}

/* **************************************************************************
 * bool	cmp(t_node *node_1, t_node *node_2)
 *
 * Summary of the function:
 * 
 * 	This function checks if node_1 is bigger than node_2
 *
 * Parameters : The two nodes in the list.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	cmp(t_node *node_1, t_node *node_2)
{
	if (node_1->value > node_2->value)
		return (true);
	else if (node_2->value > node_1->value)
		return (false);
	else
		exit(EXIT_FAILURE);
}

/* **************************************************************************
 * bool	is_smallest(t_node *head, t_node *tail, t_node *node)
 *
 * Summary of the function:
 * 
 * 	This function checks if the node is the smallest in the list.
 *
 * Parameters : The head and tail nodes in the list and a target node.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	is_smallest(t_node *head, t_node *tail, t_node *node)
{
	t_node	*curr;

	curr = head->next;
	while (curr != tail->prev)
	{
		if (node->value > curr->value)
			return (false);
		curr = curr->next;
	}
	return (true);
}

/* **************************************************************************
 * bool	is_largest(t_node *head, t_node *tail, t_node *node)
 *
 * Summary of the function:
 * 
 * 	This function checks if the node is the largest in the list.
 *
 * Parameters : The head and tail nodes in the list and a target node.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	is_largest(t_node *head, t_node *tail, t_node *node)
{
	t_node	*curr;

	curr = head->next;
	while (curr != tail->prev)
	{
		if (node->value < curr->value)
			return (false);
		curr = curr->next;
	}
	return (true);
}
