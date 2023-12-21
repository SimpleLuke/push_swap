/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:51:25 by llai              #+#    #+#             */
/*   Updated: 2023/12/21 19:11:45 by llai             ###   ########.fr       */
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
void	target_to_b(t_node *head_a, t_node *tail_a,
			t_node *head_b, t_node *tail_b);

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
	(void)head_a;
	(void)tail_a;
	sort_first_chunk(head_a, tail_a, head_b, tail_b);
}

void	sort_first_chunk(t_node *head_a, t_node *tail_a,
			t_node *head_b, t_node *tail_b)
{
	t_chunk	*chunk;
	int	top;
	int	bot;
	int	top_steps;
	int	bot_steps;

	//(void)head_b;
	//(void)tail_b;
	chunk = create_chunk(head_a, tail_a);
	while (chunk_in_stack(head_a, tail_a, chunk))
	{
		top_steps = steps_from_top(chunk, head_a, tail_a, &top);
		bot_steps = steps_from_bot(chunk, head_a, tail_a, &bot);
		if (top_steps < bot_steps)
			rotate_target(head_a, tail_a, top_steps, false);
		else
			rotate_target(head_a, tail_a, bot_steps, true);
		target_to_b(head_a, tail_a, head_b, tail_b);
	}
	
	/*
	ft_printf("TOP STEPS: %d\n", steps_from_top(chunk, head, tail, &top));
	ft_printf("BOT STEPS: %d\n", steps_from_bot(chunk, head, tail, &bot));
	ft_printf("PUSH NUM: %d\n", top);
	ft_printf("PUSH NUM: %d\n", bot);
	*/
	free(chunk);
}

void	target_to_b(t_node *head_a, t_node *tail_a,
			t_node *head_b, t_node *tail_b)
{
	if (head_b->next != tail_b && is_largest(head_b, tail_b, head_a->next) )
	{
		push_b(head_a, head_b, tail_a);
	}
	else if (head_b->next != tail_b && is_smallest(head_b, tail_b, head_a->next))
	{
		push_b(head_a, head_b, tail_a);
	}
	else
	{
		push_b(head_a, head_b, tail_a);
	}
}
