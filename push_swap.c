/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:28:38 by llai              #+#    #+#             */
/*   Updated: 2023/12/20 20:25:07 by llai             ###   ########.fr       */
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

void	push_swap(t_node *head_a, t_node *tail_a, int len);

int	main(int argc, char **argv)
{
	t_node	*head;
	t_node	*tail;

	if (argc < 2)
		return (-1);
	check_valid_arg(argv + 1, argc - 1);
	head = create_new_node(-1);
	tail = create_new_node(-1);
	init_list(argv + 1, argc - 1, head, tail);
	if (!is_sorted(head, tail))
		push_swap(head, tail, argc - 1);
	free_list(head, tail);
	exit(EXIT_SUCCESS);
}

void	print_list(t_node *head, t_node *tail)
{
	//temp - print
	t_node *curr = head->next;
	while (curr != tail)
	{
		ft_printf("%d->", curr->value);
		curr = curr->next;
	}
	ft_printf("\n");
}

void	push_swap(t_node *head_a, t_node *tail_a, int len)
{
	t_node	*head_b;
	t_node	*tail_b;

	head_b = create_new_node(-1);
	tail_b = create_new_node(-1);
	head_b->next = tail_b;
	tail_b->prev = head_b;
	/*
	ft_printf("Before\n");
	print_list(head_a, tail_a);
	print_list(head_b, tail_b);

	push_b(head_a, head_b, tail_a);
	print_list(head_a, tail_a);
	print_list(head_b, tail_b);

	push_b(head_a, head_b, tail_a);
	print_list(head_a, tail_a);
	print_list(head_b, tail_b);

	rotate_both(head_a, tail_a, head_b, tail_b);
	print_list(head_a, tail_a);
	print_list(head_b, tail_b);

	rotate_rev_both(head_a, tail_a, head_b, tail_b);
	print_list(head_a, tail_a);
	print_list(head_b, tail_b);
	*/
	if (len <= 3)
		sort_small_size(head_a, tail_a);
	else if (len <= 5)
		sort_mid_size(head_a, tail_a, head_b, tail_b);
	/*
	ft_printf("DONE:\n");
	print_list(head_a, tail_a);
	print_list(head_b, tail_b);
	*/
	free_list(head_b, tail_b);
}
