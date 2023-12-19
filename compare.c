/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:12:58 by llai              #+#    #+#             */
/*   Updated: 2023/12/19 11:28:18 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	is_sorted(t_node *head, t_node *tail);

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
