/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:50:12 by llai              #+#    #+#             */
/*   Updated: 2023/12/20 09:47:42 by llai             ###   ########.fr       */
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

static void	sa_ra(t_node *head, t_node *tail);
static void	sa_rra(t_node *head, t_node *tail);

void	sort_small_size(t_node *head, t_node *tail)
{
	t_node	*top;
	t_node	*mid;
	t_node	*bot;

	top = head->next;
	mid = head->next->next;
	bot = head->next->next->next;
	if (bot == tail && cmp(top, mid))
	{
		swap_a(head, 1);
		return ;
	}
	if (!cmp(top, mid) && cmp(mid, bot) && !cmp(bot, top))
		rotate_rev_a(head, tail, 1);
	else if (cmp(top, mid) && !cmp(mid, bot) && !cmp(bot, top))
		rotate_a(head, tail, 1);
	else if (cmp(top, mid) && !cmp(mid, bot) && cmp(bot, top))
		swap_a(head, 1);
	else if (!cmp(top, mid) && cmp(mid, bot) && cmp(bot, top))
		sa_ra(head, tail);
	else if (cmp(top, mid) && cmp(mid, bot) && !cmp(bot, top))
		sa_rra(head, tail);
}

static void	sa_ra(t_node *head, t_node *tail)
{
	swap_a(head, 1);
	rotate_a(head, tail, 1);
}

static void	sa_rra(t_node *head, t_node *tail)
{
	swap_a(head, 1);
	rotate_rev_a(head, tail, 1);
}
