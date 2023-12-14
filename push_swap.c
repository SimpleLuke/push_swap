/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:28:38 by llai              #+#    #+#             */
/*   Updated: 2023/12/14 11:35:31 by llai             ###   ########.fr       */
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
	int	size;

	(void)argv;
	if (argc < 2)
		return (0);
	size = stack_size(argv);
	
}