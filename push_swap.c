/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:28:38 by llai              #+#    #+#             */
/*   Updated: 2023/12/19 10:35:24 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This program contains code which sorts a stack of integers.
 *  	The program performs sorting by the following instructions:
 *  	- sa(swap a), sb(swap b), ss(sa & sb)
 *  	- pa(push a), pb(push b)
 *  	- ra(rotate a), rb(rotate b), rr(ra & rb)
 *  	- rra(reverse rotate a), rrb(reverse rotate b), rrr(rra & rrb)
 *  	The program displays the smallest list of instructions possible
 *  	to sort the stack.
 *
 * ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head;
	t_node	*tail;

	if (argc < 2)
		return (-1);
	check_valid_arg(argv + 1, argc - 1);
	head = create_new_node(-1);
	tail = create_new_node(-1);
	head->next = tail;
	tail->prev = head;
	init_list(argv + 1, argc - 1, head, tail);
	t_node *curr = head->next;
	while (curr != tail)
	{
		ft_printf("%d->", curr->value);
		curr = curr->next;
	}
//	push_swap(first, size);
}
