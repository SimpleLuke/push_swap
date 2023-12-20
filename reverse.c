/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:03:31 by llai              #+#    #+#             */
/*   Updated: 2023/12/20 21:10:30 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_reverse_between(t_node *head, t_node *tail, int num);
bool	is_reverse_small(t_node *head, t_node *tail, int smallest);

/* **************************************************************************
 * bool	is_reverse_betwwen(t_node *head, t_node *tail, int num)
 *
 * Summary of the function:
 * 
 * 	This function checks if the rotation needs to be reverse rotating.
 *
 * Parameters : The head and tail nodes in the list and the number to determine.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	is_reverse_between(t_node *head, t_node *tail, int num)
{
	t_node	*curr;
	t_node	*pointer;
	int		count;
	int		sum;

	count = 0;
	sum = 0;
	curr = head->next;
	pointer = head->next;
	while (pointer->next != tail)
	{
		sum++;
		pointer = pointer->next;
	}
	while (curr->next != tail)
	{
		count++;
		if ((curr->value < num && curr->next->value > num))
			break ;
		curr = curr->next;
	}
	if (count > sum - count)
		return (true);
	else
		return (false);
}

/* **************************************************************************
 * bool	is_reverse(t_node *head, t_node *tail, int smallest)
 *
 * Summary of the function:
 * 
 * 	This function checks if the rotation needs to be reverse rotating.
 *
 * Parameters : The head and tail nodes in the list and the number to determine.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	is_reverse_small(t_node *head, t_node *tail, int smallest)
{
	t_node	*curr;
	t_node	*pointer;
	int		count;
	int		sum;

	count = 0;
	sum = 0;
	curr = head->next;
	pointer = head->next;
	while (pointer->next != tail)
	{
		sum++;
		pointer = pointer->next;
	}
	while (curr->next != tail)
	{
		if (curr->value == smallest)
			break ;
		count++;
		curr = curr->next;
	}
	if (count > sum - count)
		return (true);
	else
		return (false);
}
