/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:50:12 by llai              #+#    #+#             */
/*   Updated: 2023/12/20 09:24:37 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This program is a part of push_swap program.
 *  	This program contains code which sorts a stack of integers
 *  	with a size of 3 list.
 *  	Since there are limited options for a size of 3 list,
 *  	we can sort it with simple operations.
 *
 * ************************************************************************** */

#include "push_swap.h"

void	sort_small_size(t_node *head, t_node *tail)
{
	t_node	*top;
	t_node	*middle;
	t_node	*bottom;

	top = head->next;
	middle = head->next->next;
	bottom = head->next->next->next;

	if (bottom == tail && cmp_nodes(top, middle))
		swap_a(head, 1);
}
