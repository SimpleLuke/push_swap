/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:15:17 by llai              #+#    #+#             */
/*   Updated: 2023/12/21 19:11:09 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_target(t_node *head, t_node *tail, int step, bool rev)
{
	while (step > 0)
	{
		if (rev)
			rotate_rev_a(head, tail, 1);
		else
			rotate_a(head, tail, 1);
		step--;
	}
}

int		steps_from_top(t_chunk *chunk, t_node *head, t_node *tail, int *num)
{
	t_node	*curr;
	int		steps;

	steps = 0;
	curr = head->next;
	while (curr != tail)
	{
		if (is_in_chunk(curr->value, chunk))
			break ;
		steps++;
		curr = curr->next;
	}
	*num = curr->value;
	return (steps);
}

int		steps_from_bot(t_chunk *chunk, t_node *head, t_node *tail, int *num)
{
	t_node	*curr;
	int		steps;

	steps = 0;
	curr = tail->prev;
	while (curr != head)
	{
		if (is_in_chunk(curr->value, chunk))
			break ;
		steps++;
		curr = curr->prev;
	}
	*num = curr->value;
	return (steps + 1);
}

bool	chunk_in_stack(t_node *head, t_node *tail, t_chunk *chunk)
{
	t_node *curr;

	curr = head->next;
	while (curr != tail)
	{
		if (is_in_chunk(curr->value, chunk))
			return (true);
		curr = curr->next;
	}
	return (false);
}
