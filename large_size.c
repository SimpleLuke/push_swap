/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:51:25 by llai              #+#    #+#             */
/*   Updated: 2023/12/21 17:06:39 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This program is a part of push_swap program.
 *  	This program contains code which sorts a stack of integers
 *  	with a size of 100 list.
 *  	Since there are limited options for a size of 100 list,
 *  	we can sort it with simple operations.
 *
 * ************************************************************************** */

#include "push_swap.h"

void	sort_large_size(t_node *head, t_node *tail,
			t_node *head_b, t_node *tail_b);
void	sort_first_chunk(t_node *head, t_node *tail,
			t_node *head_b, t_node *tail_b);
int		steps_from_top(int *chunk, t_node *head, t_node *tail, int *num);
int		steps_from_bot(int *chunk, t_node *head, t_node *tail, int *num);
void	rotate_target(t_node *head, t_node *tail, int step, bool rev);

/* **************************************************************************
 * void	sort_large_size(t_node *head_a, t_node *tail_a,
 * 						t_node *head_b, t_node *tail_b)
 *
 * Summary of the function:
 * 
 * 	This function sorts a list with a size of 100  or less.
 * 	It outputs the operation intrustions.
 *
 * Parameters : The head node and the tail node of the list.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	sort_large_size(t_node *head_a, t_node *tail_a,
			t_node *head_b, t_node *tail_b)
{
	(void)head_b;
	(void)tail_b;
	sort_first_chunk(head_a, tail_a, head_b, tail_b);
}

void	sort_first_chunk(t_node *head, t_node *tail,
			t_node *head_b, t_node *tail_b)
{
	int	*chunk;
	int	top;
	int	bot;
	int	top_steps;
	int	bot_steps;

	(void)head_b;
	(void)tail_b;
	chunk = create_chunk(head, tail);
	top_steps = steps_from_top(chunk, head, tail, &top);
	bot_steps = steps_from_bot(chunk, head, tail, &bot);
	if (top_steps < bot_steps)
		rotate_target(head, tail, top_steps, false);
	else
		rotate_target(head, tail, bot_steps, true);
	/*
	ft_printf("TOP STEPS: %d\n", steps_from_top(chunk, head, tail, &top));
	ft_printf("BOT STEPS: %d\n", steps_from_bot(chunk, head, tail, &bot));
	ft_printf("PUSH NUM: %d\n", top);
	ft_printf("PUSH NUM: %d\n", bot);
	*/
	free(chunk);
}

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

int		steps_from_top(int *chunk, t_node *head, t_node *tail, int *num)
{
	t_node	*curr;
	int		steps;

	steps = 0;
	curr = head->next;
	while (curr != tail)
	{
		if (is_in_chunk(curr->value, chunk, list_size(head, tail)))
			break ;
		steps++;
		curr = curr->next;
	}
	*num = curr->value;
	return (steps);
}

int		steps_from_bot(int *chunk, t_node *head, t_node *tail, int *num)
{
	t_node	*curr;
	int		steps;

	steps = 0;
	curr = tail->prev;
	while (curr != head)
	{
		if (is_in_chunk(curr->value, chunk, list_size(head, tail)))
			break ;
		steps++;
		curr = curr->prev;
	}
	*num = curr->value;
	return (steps + 1);
}
