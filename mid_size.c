/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:50:12 by llai              #+#    #+#             */
/*   Updated: 2023/12/20 12:23:00 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This program is a part of push_swap program.
 *  	This program contains code which sorts a stack of integers
 *  	with a size of 5 list.
 *  	Since there are limited options for a size of 5 list,
 *  	we can sort it with simple operations.
 *
 * ************************************************************************** */

#include "push_swap.h"

//static void	sa_ra(t_node *head, t_node *tail);
//static void	sa_rra(t_node *head, t_node *tail);

/* **************************************************************************
 * void	sort_mid_size(t_node *head_a, t_node *tail_a,
 * 						t_node *head_b, t_node *tail_b)
 *
 * Summary of the function:
 * 
 * 	This function sorts a list with a size of five or less.
 * 	It outputs the operation intrustions.
 *
 * Parameters : The head node and the tail node of the list.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	sort_mid_size(t_node *head_a, t_node *tail_a,
			t_node *head_b, t_node *tail_b)
{
	int	smallest;
	int	largest;

	push_b(head_a, head_b, tail_a);
	push_b(head_a, head_b, tail_a);
	sort_small_size(head_a, tail_a);
	/*
	while (head_b->next->next != tail_b)
	{
		if (head_a->next->value < head_b->next->value &&
				head_a->next->next->value > head_b->next->value)
		{
			rotate_a(head_a, tail_a, 1);
			push_a(head_a, head_b, tail_b);
		}
	}
	*/
	while (head_b->next != tail_b)
	{
		smallest = smallest_in_list(head_a, tail_a);
		largest = largest_in_list(head_a, tail_a);
		if (head_b->next->value < smallest)
		{
			while (head_a->next->value != smallest)
				rotate_a(head_a, tail_a, 1);
			push_a(head_a, head_b, tail_b);
		}
		else if (head_b->next->value > largest)
		{
			while (head_a->next->value != smallest)
				rotate_a(head_a, tail_a, 1);
			push_a(head_a, head_b, tail_b);
			rotate_a(head_a, tail_a, 1);
		}
		else
		{
			while (!(head_a->next->value < head_b->next->value &&
					head_a->next->next->value > head_b->next->value))
				rotate_a(head_a, tail_a, 1);
			rotate_a(head_a, tail_a, 1);
			push_a(head_a, head_b, tail_b);
		}
	}

	/*
	while (!is_sorted(head_a, tail_a))
		rotate_rev_a(head_a, tail_a, 1);
		*/
}

/* **************************************************************************
 * static void	sa_ra(t_node *head, t_node *tail)
 *
 * Summary of the function:
 * 
 * 	This function helps refactoring.
 * 	It runs swap_a and rotate_a.
 *
 * Parameters : The head node and the tail node of the list.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
/*
static void	sa_ra(t_node *head, t_node *tail)
{
	swap_a(head, 1);
	rotate_a(head, tail, 1);
}
*/

/* **************************************************************************
 * static void	sa_rra(t_node *head, t_node *tail)
 *
 * Summary of the function:
 * 
 * 	This function helps refactoring.
 * 	It runs swap_a and rotate_rev_a.
 *
 * Parameters : The head node and the tail node of the list.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
/*
static void	sa_rra(t_node *head, t_node *tail)
{
	swap_a(head, 1);
	rotate_rev_a(head, tail, 1);
}
*/
