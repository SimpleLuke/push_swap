/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:50:12 by llai              #+#    #+#             */
/*   Updated: 2023/12/20 21:05:21 by llai             ###   ########.fr       */
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

void	sort_smallest(t_node *head_a, t_node *head_b,
			t_node *tail_a,	t_node *tail_b);
void	final_sort(t_node *head_a, t_node *tail_a);
void	sort_largest(t_node *head_a, t_node *head_b,
			t_node *tail_a,	t_node *tail_b);
void	sort_other(t_node *head_a, t_node *head_b,
			t_node *tail_a,	t_node *tail_b);

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
	while (head_b->next != tail_b)
	{
		smallest = smallest_in_list(head_a, tail_a);
		largest = largest_in_list(head_a, tail_a);
		if (head_b->next->value < smallest)
			sort_smallest(head_a, head_b, tail_a, tail_b);
		else if (head_b->next->value > largest)
			sort_largest(head_a, head_b, tail_a, tail_b);
		else
			sort_other(head_a, head_b, tail_a, tail_b);
	}
	final_sort(head_a, tail_a);
}

/* **************************************************************************
 * void	sort_largest(t_node *head_a, t_node *head_b,
 *			t_node *tail_a,	t_node *tail_b)
 *
 * Summary of the function:
 * 
 * 	This function puts the stack b number into stack a with a correct order
 * 	as if the number is the largest in the list
 *
 * Parameters : The head node and the tail node of the both lists.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	sort_largest(t_node *head_a, t_node *head_b,
			t_node *tail_a,	t_node *tail_b)
{
	int	smallest;

	smallest = smallest_in_list(head_a, tail_a);
	if (is_reverse_small(head_a, tail_a, smallest))
		while (head_a->next->value != smallest)
			rotate_rev_a(head_a, tail_a, 1);
	else
		while (head_a->next->value != smallest)
			rotate_a(head_a, tail_a, 1);
	push_a(head_a, head_b, tail_b);
}

/* **************************************************************************
 * void	sort_smallest(t_node *head_a, t_node *head_b,
 *			t_node *tail_a,	t_node *tail_b)
 *
 * Summary of the function:
 * 
 * 	This function puts the stack b number into stack a with a correct order
 * 	as if the number is the smallest in the list
 *
 * Parameters : The head node and the tail node of the both lists.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	sort_smallest(t_node *head_a, t_node *head_b,
			t_node *tail_a,	t_node *tail_b)
{
	int	smallest;

	smallest = smallest_in_list(head_a, tail_a);
	if (is_reverse_small(head_a, tail_a, smallest))
		while (head_a->next->value != smallest)
			rotate_rev_a(head_a, tail_a, 1);
	else
		while (head_a->next->value != smallest)
			rotate_a(head_a, tail_a, 1);
	push_a(head_a, head_b, tail_b);
}

/* **************************************************************************
 * void	sort_other(t_node *head_a, t_node *head_b,
 *			t_node *tail_a,	t_node *tail_b)
 *
 * Summary of the function:
 * 
 * 	This function puts the stack b number into stack a with a correct order
 * 	as if the number is not the largest or smallest.
 *
 * Parameters : The head node and the tail node of the both lists.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	sort_other(t_node *head_a, t_node *head_b,
			t_node *tail_a,	t_node *tail_b)
{
	if (is_reverse_between(head_a, tail_a, head_b->next->value))
		while (!(head_a->next->value > head_b->next->value
					&& tail_a->prev->value < head_b->next->value))
		rotate_rev_a(head_a, tail_a, 1);
		/*
		while (!(head_a->next->value < head_b->next->value
				&& head_a->next->next->value > head_b->next->value))
			rotate_rev_a(head_a, tail_a, 1);
			*/
	else
		while (!(head_a->next->value > head_b->next->value
					&& tail_a->prev->value < head_b->next->value))
			rotate_a(head_a, tail_a, 1);
	/*
		while (!(head_a->next->value < head_b->next->value
				&& head_a->next->next->value > head_b->next->value))
			rotate_a(head_a, tail_a, 1);
			*/
	push_a(head_a, head_b, tail_b);
}

/* **************************************************************************
 * void	final_sort(t_node *head_a, t_node *tail_a)
 *
 * Summary of the function:
 * 
 * 	This function sorts the list by rotating/ reverse rotating the list 
 *
 * Parameters : The head node and the tail node of the both lists.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	final_sort(t_node *head_a, t_node *tail_a)
{
	int	smallest;

	smallest = smallest_in_list(head_a, tail_a);
	if (is_reverse_small(head_a, tail_a, smallest))
		while (!is_sorted(head_a, tail_a))
			rotate_rev_a(head_a, tail_a, 1);
	else
		while (!is_sorted(head_a, tail_a))
			rotate_a(head_a, tail_a, 1);
}
